/**
 * ============================================================
 *  Nexus    : A Tiny IoT Desk Clock
 *  Author   : Kishan Pratap Singh
 *  Hardware : Waveshare ESP32-C3-Zero + 0.96" OLED (SSD1315)
 * ============================================================
 */
#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// -------------------- SPI Pin definitions --------------------
#define OLED_MOSI   21
#define OLED_SCK    20
#define OLED_DC     5
#define OLED_CS     6
#define OLED_RESET  7

Adafruit_SSD1306 display(128, 64, OLED_MOSI, OLED_SCK, OLED_DC, OLED_RESET, OLED_CS);

// -------------------- WiFi credentials --------------------
const char *ssid     = "Your SSID";
const char *password = "Your Password";

// -------------------- NTP settings (India UTC+5:30) --------------------
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000);

// -------------------- Display timing --------------------
unsigned long lastUpdate     = 0;
const long    updateInterval = 1000;

// ----------------------------------------------------------------------
// Helper: draw text perfectly centered (horizontal + vertical)
// ----------------------------------------------------------------------
void drawCenterText(String text, int textSize) {
  display.setTextSize(textSize);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  // center horizontally
  int x = (128 - w) / 2;
  // center vertically: baseline = (screen height - text height)/2 + text height - descent
  int y = (64 - h) / 2 + h - 1;
  display.setCursor(x, y);
  display.print(text);
}

// ----------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(100);

  // --- Initialize OLED in SPI mode ---
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306/SSD1315 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();

  // --- Show "Connecting..." (small, centered) ---
  display.clearDisplay();
  drawCenterText("Connecting...", 1);   // size 1 = small
  display.display();

  // --- Start WiFi ---
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(250);
    attempts++;
  }

  // --- Show connection status (small, centered) ---
  display.clearDisplay();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi!");
    drawCenterText("Connected", 1);
  } else {
    Serial.println("\nFailed to connect to WiFi");
    drawCenterText("No WiFi", 1);
  }
  display.display();
  delay(1500);   // show status briefly

  // --- Start NTP ---
  timeClient.begin();
  timeClient.update();
}

// ----------------------------------------------------------------------
// Helper: format two digits
// ----------------------------------------------------------------------
String formatTwoDigits(int number) {
  return number < 10 ? "0" + String(number) : String(number);
}

// ----------------------------------------------------------------------
// Helper: draw text centered horizontally (for date & time)
// ----------------------------------------------------------------------
void drawCenteredText(String text, int y, int textSize) {
  display.setTextSize(textSize);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  display.setCursor((128 - w) / 2, y);
  display.print(text);
}

// ----------------------------------------------------------------------
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastUpdate >= updateInterval) {
    lastUpdate = currentMillis;

    // Update NTP if WiFi is connected
    if (WiFi.status() == WL_CONNECTED) {
      timeClient.update();
    }

    // Get current time
    time_t epochTime = timeClient.getEpochTime();
    struct tm *ptm = gmtime(&epochTime);

    // Blinking colon
    static bool showColon = true;
    showColon = !showColon;

    // Convert to 12-hour format
    int hour = ptm->tm_hour;
    String period = hour < 12 ? "AM" : "PM";
    hour = hour % 12;
    if (hour == 0) hour = 12;

    // Build time string with blinking colon
    String timeStr = formatTwoDigits(hour) + (showColon ? ":" : " ") + formatTwoDigits(ptm->tm_min) + " " + period;

    display.clearDisplay();

    // --- Date bar (white background) ---
    display.fillRect(0, 0, 128, 28, SSD1306_WHITE);
    display.setTextColor(SSD1306_BLACK);
    String dateStr = formatTwoDigits(ptm->tm_mday) + "/" + formatTwoDigits(ptm->tm_mon + 1) + "/" + String(ptm->tm_year + 1900);
    drawCenteredText(dateStr, 10, 2);

    // --- Time (large, with blinking colon) ---
    display.setTextColor(SSD1306_WHITE);
    String timePart = timeStr.substring(0, 5);   // HH:MM or HH MM
    display.setTextSize(3);
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(timePart, 0, 0, &x1, &y1, &w, &h);
    display.setCursor((128 - w) / 2 - 10, 38);
    display.print(timePart);

    // AM / PM suffix
    display.setTextSize(2);
    display.setCursor((128 - w) / 2 + w - 5, 42);
    display.print(timeStr.substring(6));   // " AM" / " PM"

    display.display();
  }

  // Reconnect WiFi every 10 seconds if needed
  static unsigned long lastWifiCheck = 0;
  if (currentMillis - lastWifiCheck >= 10000) {
    lastWifiCheck = currentMillis;
    if (WiFi.status() != WL_CONNECTED) {
      WiFi.reconnect();
    }
  }
}
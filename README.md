<div align="center">

<br/>

<img src="Circuit%20Diagram/NX.png" width="900"/>

<br/><br/>

# Nexus

**A Tiny IoT Desk Clock — Minimal by Design, Always in Sync**

<br/>

[![youtube](https://www.readmecodegen.com/api/social-icon?name=youtube&size=32&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Fyoutube.com%2F%40NextBuilderIO)](https://youtube.com/@NextBuilderIO)
[![instagram](https://www.readmecodegen.com/api/social-icon?name=instagram&size=32&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Finstagram.com%2Fnext_builder)](https://instagram.com/next_builder)
[![x](https://www.readmecodegen.com/api/social-icon?name=x&size=34&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Fx.com%2FNEXTBUILDERIO)](https://x.com/NEXTBUILDERIO)
[![linkedin](https://www.readmecodegen.com/api/social-icon?name=linkedin&size=32&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true)](https://www.linkedin.com/company/nextbuilderIO/)
[![instructables](https://www.readmecodegen.com/api/social-icon?name=instructables&size=30&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Fwww.instructables.com%2Fmember%2FNext%2520Builder%2520DIY%2F)](https://www.instructables.com/member/Next%20Builder%20DIY/)
[![hackster](https://www.readmecodegen.com/api/social-icon?name=hackster&size=30&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Fhackster.io%2FNEXTBUILDER)](https://hackster.io/NEXTBUILDER)
[![hackaday](https://www.readmecodegen.com/api/social-icon?name=hackaday&size=32&shape=circle&reverseBackground=true&textAlignment=horizontal&showText=true&link=https%3A%2F%2Fhackaday.io%2FNextBuilder)](https://hackaday.io/NextBuilder)

<br/>

</div>

<br/>

## 🕒 Overview

In today's world, even something as simple as checking the time often leads to unnecessary distractions. We unlock our phones for a quick glance, only to be interrupted by notifications, messages, or social media. **Nexus** was built to solve exactly that problem, with a simple philosophy: display only the information that matters, so you can stay focused on what you're doing.

Powered by the **Waveshare ESP32-C3**, Nexus connects to Wi-Fi and synchronizes with **Network Time Protocol (NTP)** servers to keep accurate, real-time date and time — with no traditional RTC module and no manual adjustments required. Time is shown in **12-hour (HH:MM AM/PM)** format, and the date in **DD/MM/YYYY** format, on a crisp **0.96" OLED display**.

The enclosure was designed from scratch in **Autodesk Fusion 360**, giving Nexus a clean, product-like appearance that blends naturally into any desk setup. This repository contains everything needed to build your own: complete firmware source, CAD files, STL models, and wiring diagrams.

<br/>

## 🎬 Demo

<div align="center">
<a href="https://www.youtube.com/watch?v=yCyvsM48buc">
<img src="https://img.youtube.com/vi/yCyvsM48buc/maxresdefault.jpg" width="800"/>
</a>
<br/><br/>
<sub>▶ Click to watch the full build and demo on YouTube</sub>
</div>

<br/>

<br/>

## 🔩 Hardware Used

<div align="center">
<img src="Circuit%20Diagram/1.png" width="700"/>
<br/><br/>
  
<sub>Components used to build Nexus</sub>
  
</div>

Nexus keeps its parts list intentionally short — a **Waveshare ESP32-C3** handles Wi-Fi and processing, paired with a **0.96" OLED display** for output. The full wiring and circuit diagram is available in the [Circuit Diagram](https://github.com/NextBuilder/Nexus/tree/main/Circuit%20Diagram) folder of this repository.

<br/>

<br/>

## ⚙️ How It Works

Once powered on, **Nexus** connects to the configured Wi-Fi network and synchronizes the current date and time with a public **Network Time Protocol (NTP)** server. This removes the need for a traditional Real-Time Clock (RTC) module, so the displayed time stays accurate without manual adjustments or a backup battery.

The **Waveshare ESP32-C3** processes the received time data and continuously updates the **0.96" OLED display**, showing the current date in **DD/MM/YYYY** format and the current time in **12-hour (HH:MM)** format with an **AM/PM** indicator. The display refreshes automatically, keeping the information accurate and easy to read at a glance.

By combining Wi-Fi connectivity, NTP synchronization, and a clean, distraction-free interface, Nexus offers a simple, reliable way to keep track of time while helping you stay focused on your work.

<br/>

<br/>

## 📚 Build Guide & Documentation

Want to build your own **Nexus**? Complete step-by-step instructions, wiring details, assembly photos, and testing procedures are available in the full written tutorials below.

Whether you're a beginner exploring IoT and embedded displays or an experienced maker looking to customize the design, these guides walk through the entire build process from start to finish.

### Tutorials & Project Documentation

* **Instructables**
  https://www.instructables.com/Next-Time-a-Tiny-Desk-Clock/

* **Hackster.io**
  https://www.hackster.io/NEXTBUILDER/nexus-a-tiny-iot-desk-clock-2d65fd

* **Hackaday.io**
  https://hackaday.io/project/206091-nexus-a-tiny-iot-desk-clock

All project resources, including firmware, CAD models, library configuration files, and circuit diagrams, are available in this GitHub repository.

<br/>

<br/>

## License

Open for **personal and educational use only.**
Commercial use, resale, or redistribution in any product requires explicit written permission from the author.

<br/>

<br/>

<div align="center">

Built with ❤️ by **[Next Builder](https://youtube.com/@nextbuilderio)**

</div>

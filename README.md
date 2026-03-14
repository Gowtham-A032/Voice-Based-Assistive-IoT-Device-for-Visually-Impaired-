# Voice-Based Assistive IoT Device for Visually Impaired Students

## 📖 Overview
This project is a **voice-driven assistive IoT device** designed to support visually impaired students in their learning journey.  
Built on **Arduino Mega2560** and integrated with the **ChatGPT IoT Master API**, the device accepts voice commands and responds with real-time educational assistance.  

It combines **microphone, speaker, LCD, and wireless connectivity** to deliver accessible, AI-powered interaction.

---

## ⚙️ Features
- 🎙️ **Voice Input**: Accepts spoken questions via microphone.  
- 🔊 **Audio Output**: Provides spoken answers using text-to-speech.  
- 📟 **LCD Display**: Displays responses for monitoring/debugging.  
- 🌐 **Wi-Fi Connectivity**: Connects to IoT cloud server for ChatGPT API communication.  
- 🧑‍🎓 **Educational Assistance**: Real-time Q&A designed for visually impaired students.  
- 🔧 **Hardware Control**: Example motor control commands (`Motor on`, `Motor off`) included.

---

## 🛠️ Hardware Requirements
- Arduino Mega2560  
- ESP32 / IoT Master Processor  
- Microphone module  
- Speaker (I2S compatible)  
- LCD (16x2, connected via LiquidCrystal library)  
- Push button (for interaction control)  
- Wi-Fi access point  

---

## 📦 Libraries Used
- `Arduino.h`  
- `WiFi.h`  
- `HTTPClient.h`  
- `ArduinoJson.h`  
- `Audio.h`  
- `UrlEncode.h`  
- `LiquidCrystal.h`  

Install these via Arduino IDE Library Manager or manually add them to your `libraries/` folder.

---

## 📂 File Structure

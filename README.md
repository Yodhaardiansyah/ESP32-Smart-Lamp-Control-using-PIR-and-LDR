# 🌟 **ESP32 Smart Lamp: Motion & Light-Based Automation** 🌟  

### 🔹 **Project Overview**  
This ESP32-based **smart lamp system** uses a **PIR motion sensor** and an **LDR light sensor** to automatically control a **relay**.  

💡 **Key Features:**  
✅ **Motion-activated lighting** (only in the dark)  
✅ **Auto turn-off after 5 seconds of no motion**  
✅ **Prevents unnecessary power consumption**  
✅ **Real-time sensor monitoring via Serial Monitor**  

---

## 🔧 **Required Components**  
| Component           | Description                        |
|--------------------|--------------------------------|
| **ESP32**         | Microcontroller board         |
| **PIR Sensor**    | Detects motion               |
| **LDR Sensor**    | Detects ambient light levels |
| **Relay Module**  | Controls lamp power          |
| **Jumper Wires**  | For circuit connections      |

---

## ⚡ **Wiring Diagram**  

| Component   | ESP32 Pin |
|------------|----------|
| **PIR Sensor** | GPIO25   |
| **LDR Sensor** | GPIO12   |
| **Relay**      | GPIO13   |

---

## 🎯 **How It Works**  
1️⃣ **Motion Detected in Darkness** → **Relay ON (Lamp ON)**  
2️⃣ **No Motion but within 5s** → **Relay Stays ON**  
3️⃣ **No Motion for 5s** → **Relay OFF (Lamp OFF)**  
4️⃣ **Bright Environment** → **Relay Always OFF**  

🛑 **Failsafe:** The relay won’t activate if the room is already bright.  

---

## 📜 **Code Explanation**  
🔹 The **PIR sensor** detects motion and sends a **HIGH signal** when movement occurs.  
🔹 The **LDR sensor** detects light levels and determines if it’s **day or night**.  
🔹 The **relay turns ON if motion is detected in a dark environment**.  
🔹 If no motion is detected for **5 seconds**, the **relay turns OFF**.  

---

## 🚀 **Getting Started**  
1️⃣ Install the **ESP32 board support package** in Arduino IDE.  
2️⃣ Connect the **ESP32** to your PC using a USB cable.  
3️⃣ Select the correct **board and COM port** in Arduino IDE.  
4️⃣ Upload the provided **code** to your ESP32.  
5️⃣ Open **Serial Monitor** (115200 baud rate) to see real-time sensor readings.  

---

## 🛠 **Future Enhancements (Coming Soon!)**  
✨ Add MQTT integration for remote monitoring  
✨ Implement AI-based predictive lighting control  
✨ Include an OLED display for real-time status  

---

## 👨‍💻 **Developer Credits**  
🔹 **Author:** Yodha Ardiansyah  
🔹 **Website:** [🌐 arunovasi.my.id](https://arunovasi.my.id)  
🔹 **License:** Open-source (MIT)  

🚀 *Turn your ordinary lamp into a smart one with ESP32!* 🌟

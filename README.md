# 🚗💥 EDR – Event Data Recorder in Vehicle using IoT


## 📌 Project Summary

An **IoT-based Event Data Recorder (EDR)** captures **real-time driving data** to assist in **accident detection**, **post-crash investigation**, and **driver behavior analysis**. Just like an airplane's black box, this system ensures vital vehicle data is always recorded securely and accessible remotely.

---

## 🔧 Tech Stack & Components

| 🔹 Component        | 💡 Description                          |
|--------------------|------------------------------------------|
| ⚙️ Microcontroller | Arduino Uno / ESP32                      |
| 🛰️ GPS Module       | Real-time location tracking              |
| 📶 GSM Module       | Data transmission to server              |
| 🧭 Accelerometer    | Crash / sudden brake detection (MPU6050) |
| 🔋 Power Supply     | Regulated 5V / Battery powered           |
| ☁️ Cloud Storage    | Firebase / Thingspeak (Optional)         |
| 💻 IDE              | Arduino IDE / VS Code                    |

---

## 🎯 Key Features

✅ Real-time vehicle tracking  
✅ Sudden brake / crash event detection  
✅ Live data sent via GSM to cloud/server  
✅ Data stored with timestamp for analysis  
✅ Optional alert to emergency contacts  
✅ Portable & low power consumption  

---

## 📸 Project Images

### 🖥️ Live Hardware + Monitoring  
![Live Hardware View](assets/3.jpg)

### 🔍 Full Circuit Top View  
![Top View]([assets/4.jpg](https://github.com/SnehaNikam24/EDR-In-vehicle-Using-IOT/blob/main/4.jpg))

### 🧪 Working Setup with Serial Monitor  
![Serial Monitor Output](assets/1.jpg)

---

## 🧠 System Workflow

1. **Sensors collect**: Speed, acceleration, GPS location
2. **Detect event**: Sudden brake, tilt, or crash
3. **Log + Send data**: To cloud or local storage
4. **Trigger alert**: (optional) via SMS/Email
5. **Visualize & Analyze**: On dashboard/web UI

---

## 🎥 Watch the Demo

[![Watch the Demo](https://github.com/SnehaNikam24/EDR-In-vehicle-Using-IOT/blob/main/v.mp4)

> 📺 Click above to view live demo showcasing event detection, logging, and real-time monitoring.

---

## 📊 Sample Output (JSON Format)

```json
{
  "timestamp": "2025-07-29T13:50:00Z",
  "speed": "58 km/h",
  "location": { "lat": 19.8762, "lon": 75.3433 },
  "acceleration": "2.9 m/s²",
  "event": "Sudden Brake Detected"
}
````

---

## 🔮 Future Enhancements

🚀 AI-based collision prediction
📲 Mobile app integration
📊 Realtime dashboards with graphs
🧠 Machine learning for driver scoring
🔔 Voice-based driver alerts

---

## 👨‍💻 Team Credits

| 👤 Name              | 🎓 Role                    |
| -------------------- | -------------------------- |
| Devendra Ahire       | Developer & IoT Integrator |
| \[Add teammate name] | Hardware Developer         |
| \[Add teammate name] | Code & Testing             |
| \[Add teammate name] | Cloud Integration          |

📩 **Contact**: [Senha](mailto:drahire371322@kkwagh.edu.in)


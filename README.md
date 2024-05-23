# air_Humidity_Temperature_Monitor
This project involves creating an Air, Humidity, and Temperature Monitoring System using a NodeMCU, DHT11 sensor, air quality sensor, humidity and temperature sensor, and an OLED display. The system generates real-time data and sends it to the ThingSpeak server, allowing users to monitor the environmental conditions remotely



Components
1.NodeMCU: A low-cost open-source IoT platform.
2.DHT11: A basic, ultra low-cost digital temperature and humidity sensor.
3.Air Quality Sensor: Measures the level of pollution in the air.
4.Humidity and Temperature Sensor: Provides accurate readings of ambient temperature and humidity.
5.OLED Display: Displays real-time data locally.
6.ThingSpeak: An IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud.

Features
.Real-Time Monitoring: Continuously monitors air quality, temperature, and humidity.
.Data Visualization: Displays real-time data on an OLED screen and uploads it to the ThingSpeak server.
.Remote Access: Access and monitor data remotely through the ThingSpeak web interface.
.Alerts and Notifications: Set up triggers and alerts based on threshold values in ThingSpeak.
.Setup and Installation

Hardware Connections
NodeMCU:

Connect the DHT11 sensor to the NodeMCU:
VCC to 3V3
GND to GND
Data to D4

Connect the air quality sensor to the NodeMCU (according to the sensor's pin configuration).
Connect the OLED display to the NodeMCU:
SDA to D2
SCL to D1
Power Supply: Ensure the NodeMCU and sensors are powered appropriately.

Software Installation
Arduino IDE: Install the latest version of Arduino IDE.

Libraries:

Install the following libraries from the Arduino Library Manager:
Adafruit_SSD1306
Adafruit_GFX
DHT
ThingSpeak
Code:

Clone this repository to your local machine.
Open the .ino file in Arduino IDE.
Configure your Wi-Fi credentials and ThingSpeak API key in the code.

ThingSpeak Setup
Create a ThingSpeak Account: Sign up at ThingSpeak.
Create a New Channel: Set up a new channel with fields for temperature, humidity, and air quality.
API Key: Obtain the Write API Key from your ThingSpeak channel and add it to your code.
Upload and Run
Upload Code: Upload the code to your NodeMCU.
Monitor: View the real-time data on the OLED display and monitor the data on your ThingSpeak channel.
Usage
The system will start sending real-time data to ThingSpeak once powered on.
Monitor the environmental conditions locally on the OLED display.
Access and analyze the data remotely via the ThingSpeak web interface.
Contributing
Contributions are welcome! Please fork this repository and submit pull requests for any enhancements or bug fixes.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
For questions or support, please open an issue in this repository.

![image](https://github.com/vaibhav-raj-sing/air_Humidity_Temperature_Monitor/assets/114972308/1719b49b-500f-439e-bd8b-81323c1c1478)
![image](https://github.com/vaibhav-raj-sing/air_Humidity_Temperature_Monitor/assets/114972308/b13a7387-eefb-4905-910f-b1bed59fae6c)
![image](https://github.com/vaibhav-raj-sing/air_Humidity_Temperature_Monitor/assets/114972308/3cff4705-76b8-459f-ba8f-42b757ac90eb)



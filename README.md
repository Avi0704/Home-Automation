# Home-Automation
The Ultimate DIY Smart Home Converter. This project provides the code and guide to turn any electrical switchboard into a WiFi-enabled, voice-controlled smart device using an ESP8266 and Sinric Pro.
The Ultimate DIY Smart Home Converter
This project provides the code and guide to turn any electrical switchboard into a WiFi-enabled, voice-controlled smart device using an ESP8266 and the Sinric Pro IoT platform.

It's designed to be a universal framework for converting standard home appliances into smart devices that can be controlled from anywhere via a mobile app or with voice commands through Amazon Alexa and Google Home.

Features
Universal Conversion: Adaptable to almost any standard electrical switchboard.

WiFi Control: Turn your lights, fans, or other appliances on/off from anywhere in the world.

Voice Assistant Ready: Natively works with Amazon Alexa and Google Home for hands-free voice commands (e.g., "Alexa, turn on the light").

Real-time Status: The app and voice assistants always show the correct on/off status of your devices.

Low Cost & Accessible: Built with the affordable and widely available ESP8266 and standard relay modules.

Scalable: The code is structured to be easily expandable to control more than two devices.

Hardware Required
ESP8266 Wi-Fi Module: A NodeMCU or Wemos D1 Mini is highly recommended.

2-Channel Relay Module: A 5V relay module compatible with the 3.3V logic of the ESP8266.

Power Supply: A micro-USB cable and a 5V/1A USB power adapter.

Jumper Wires: To connect the ESP8266 to the relay module.

Your Appliances: A light, a fan, or any other device you wish to make smart.

⚠️ High Voltage Warning: Please be extremely careful when working with mains voltage. If you are not experienced or confident with high-voltage wiring, consult a qualified electrician. Safety is paramount.

Software & Setup
1. Arduino IDE
Ensure you have the Arduino IDE installed and the ESP8266 board manager set up. If not, add the following URL to File > Preferences > Additional Boards Manager URLs:

[http://arduino.esp8266.com/stable/package_esp8266com_index.json](http://arduino.esp8266.com/stable/package_esp8266com_index.json)

2. Required Libraries
Install the following libraries through the Arduino Library Manager (Sketch > Include Library > Manage Libraries...):

SinricPro by Boris Jaeger

ArduinoJson by Benoit Blanchon

WebSockets by Markus Sattler

3. Sinric Pro Account
Go to sinric.pro and create a free account.

Log in and navigate to the Devices menu.

Click Add Device and create two devices of type Switch (e.g., "Light" and "Fan").

Go to the Credentials menu and copy your App Key, App Secret, and the Device IDs for your new switches. You will need these for the code.

4. Code Configuration
Open the ESP8266_SinricPro_Controller.ino file. At the top of the file, you must fill in your credentials:

Your WiFi network name (WIFI_SSID)

Your WiFi password (WIFI_PASS)

Your Sinric Pro APP_KEY

Your Sinric Pro APP_SECRET

Your Sinric Pro LIGHT_ID

Your Sinric Pro FAN_ID

Wiring Diagram
Connect the ESP8266 to the 2-channel relay module. Ensure the circuit is NOT connected to mains power while wiring.

ESP8266 (NodeMCU)

2-Channel Relay Module

VIN (5V)

VCC

GND

GND

D1 (GPIO5)

IN1 (Light)

D2 (GPIO4)

IN2 (Fan)

How to Use
Upload the Code: After filling in your credentials, select your ESP8266 board and COM port in the Arduino IDE and click Upload.

Monitor: Open the Serial Monitor at a baud rate of 115200 to see the connection status and diagnostic messages.

Control:

Download the Sinric Pro app on your phone, log in, and your devices will be ready to control.

To use voice commands, link the "Sinric Pro" skill in your Amazon Alexa or Google Home app. Your devices will appear automatically.

Enjoy your new, smarter home!

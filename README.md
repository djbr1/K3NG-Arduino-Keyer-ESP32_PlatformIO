# k3ng_cw_keyer
K3NG Arduino CW Keyer

The K3NG Keyer is an open source Arduino based CW (Morse Code) keyer with a lot of features and flexibility, rivaling commercial keyers which often cost significantly more. The code can be used with a full blown Arduino board or an AVR microcontroller chip can be programmed and used directly in a circuit. This keyer is suitable as a standalone keyer or for use permanently installed inside a rig, especially homebrew QRP rigs. It’s open source code so you can fully customize it to fit your needs and also perhaps learn from it or find coding ideas for other projects.

Documentation is located here:
https://github.com/k3ng/k3ng_cw_keyer/wiki

&nbsp; &nbsp; &nbsp; 

### Proof Of Concept Pressure Sensor Paddles using strain sensor and ADC - ESP32/Hx711 implementation
  (by HB9TXB)

#### Goal: 
Powerful and flexible keyer with reliable iambic paddle, easily built without any mechanical (machining) skills.


#### Why load sensor:
- Load sensor based paddle is self calibrating, sensitivity is adjustable from command line interface separately for dot and dash.
- In order to reduce backslash,  existing mechanical paddle design utilize ball bearings. It is an overkill as angular (rotational) movement is almost non-existent.
- Mechanical contacts prone to bouncing.
- Minimal contact distance (0.1 mm) and minimal force (10 grams) difficult to maintain with mechanical paddles.
- More reliable compared to capacitive touch paddle, behaves like usual mechanical paddle.
- Sensor paddle cost orders of magnitude cheaper than mechanical paddles.
 

#### Features:
- All [K3NG capabilities](https://github.com/k3ng/k3ng_cw_keyer/wiki) available.
- Equally suitable for beginners and experts.
- Affordable, off the shelf, load sensor and ADC components.  
  ( total approx. 10 USD CHF for two ADC and two sensors ( ADC 2x1.3 USD, sensor 2 x 2~3 USD   ))
- Boards: "compatible"  Nano board  1.8 CHF  ;   "compatible" ESP32 approx. 3-4 USD 
- Can be developed as add-on to existing K3NG kits.

#### Two Prototypes:
1) Implementation [based on ESP32 based k3ng keyer - SP5IOU](https://github.com/djbr1/K3NG-Arduino-Keyer-ESP32_PlatformIO)  has OLED SSD1306 display and command line interface over Bluetooth, allowing parameter change from [Android Bluetooth Seria Terminal ](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal). Uses Hx711 ADC.
  
2. [Arduino nano implementation](https://github.com/djbr1/k3ng_cw_keyer), allows parameter change through USB interface using [Android Serial Terminal app](https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal)  . CS1237 ADC is used.


#### TODO:    
 - PCB design
 - BoM for additional components
 - physical buttons as required
  - optocouplers and 3.5 mm jacks for PPT and TX line
 - RFI/EMI shielding
  

![](https://github.com/djbr1/K3NG-Arduino-Keyer-ESP32_PlatformIO/blob/master/images/IMG_1331.JPG?raw=true)

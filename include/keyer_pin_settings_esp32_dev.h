/*

ESP32 dev board                                                                                  
See pin assignment and limitations: https://circuits4you.com/2018/12/31/esp32-devkit-esp32-wroom-gpio-pinout/
*/

/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 32 //32 Needs external 10k Pullup can be used as touch paddle //22 //36
#define paddle_right 33 //33 Needs external 10k Pullup can be used as touch paddle23 //39
#define tx_key_line_1 25 //16 //RX2 pin //2 //18 // (high = key down/tx on) //  used for active buzzer - Tone32.h not working
#define tx_key_line_2 0 //17 //0
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 23 //5         // connect a speaker for sidetone
#define potentiometer 39 //A3 - VN pin 0 // Speed potentiometer (0 to 3.3V) Use pot from 1k to 10k
#define ptt_tx_1 26 //4              // PTT ("push to talk") lines
#define ptt_tx_2 0              //   Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

#define potentiometer_enable_pin 0  // if defined, the potentiometer will be enabled only when this pin is held low; set to 0 to ignore this pin

#ifdef FEATURE_BUTTONS
  #define analog_buttons_pin 36 //A0 //VP pin on the board Not all pins of ESP32 are available for ADC. See https://circuits4you.com/2018/12/31/esp32-devkit-esp32-wroom-gpio-pinout/
  #define command_mode_active_led 2 //for ESP32 On Board LED
#endif //FEATURE_BUTTONS

/*
FEATURE_SIDETONE_SWITCH
  Enabling this feature and an external toggle switch  adds switch control for playing cw sidetone.
  ST Switch status is displayed in the status command.  This feature will override the software control of the sidetone (\o).
  Arduino pin is assigned by SIDETONE_SWITCH 
*/

#ifdef FEATURE_SIDETONE_SWITCH
  #define SIDETONE_SWITCH 0 //15
#endif //FEATURE_SIDETONE_SWITCH


//lcd pins
#if defined (FEATURE_LCD_4BIT) || defined(FEATURE_LCD_8BIT) //corrected by SP5IOU 20210802
  #define lcd_rs 4 //32
  #define lcd_enable 16 //RX2 //33
  #define lcd_d4 17 //TX2 //25
  #define lcd_d5 5 //26
  #define lcd_d6 18 //27
  #define lcd_d7 19 //14
#endif //FEATURE_LCD_4BIT

#if defined(FEATURE_LCD_8BIT) // addition four data lines for 8 bit LCD control
  #define lcd_d0 13 // 13 Note this pin can be used for Inline debugger
  #define lcd_d1 12 // 12 Note this pin can be used for Inline debugger
  #define lcd_d2 14 // 14 Note this pin can be used for Inline debugger
  #define lcd_d3 15 // 15 Note this pin can be used for Inline debugger
#endif //FEATURE_LCD_4BIT || defined(FEATURE_LCD_8BIT)


#ifdef FEATURE_LCD1602_N07DH
  #define lcd_rs 4 //32
  #define lcd_enable 16 //RX2 //33
  #define lcd_d4 17 //TX2 //25
  #define lcd_d5 5 //26
  #define lcd_d6 18 //27
  #define lcd_d7 19 //14
#endif //FEATURE_LCD1602_N07DH

//ps2 keyboard pins
#ifdef FEATURE_PS2_KEYBOARD
  #define ps2_keyboard_data 16 
  #define ps2_keyboard_clock 17    // this must be on an interrupt capable pin!
#endif //FEATURE_PS2_KEYBOARD

// rotary encoder pins and options - rotary encoder code from Jim Balls M0CKE
#ifdef FEATURE_ROTARY_ENCODER
  #define OPTION_ENCODER_HALF_STEP_MODE     // Half-step mode?
  #define rotary_pin1  34 //34 Needs external 10k Pullup  //19  // CW Encoder Pin  Not all ESP32 pins supports PULLUP SP5IOU
  #define rotary_pin2  35 //35 Needs external 10k Pullup  //21  // CCW Encoder Pin  Not all ESP32 pins supports PULLUP SP5IOU
  #define OPTION_ENCODER_ENABLE_PULLUPS     // define to enable weak pullups.
#endif //FEATURE_ROTARY_ENCODER

#ifdef FEATURE_LED_RING
  #define led_ring_sdi    0    //Data
  #define led_ring_clk    0    //Clock
  #define led_ring_le     0    //Latch
#endif //FEATURE_LED_RING

#define correct_answer_led 0
#define wrong_answer_led 0

#ifdef FEATURE_PTT_INTERLOCK
  #define ptt_interlock 0  // this pin disables PTT and TX KEY
#endif //FEATURE_PTT_INTERLOCK

#ifdef FEATURE_STRAIGHT_KEY
  #define pin_straight_key 1 //TXD0
#endif //FEATURE_STRAIGHT_KEY

// FEATURE_CW_DECODER & OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
// See https://github.com/k3ng/k3ng_cw_keyer/wiki/385-Feature:-CW-Decoder for details
#define cw_decoder_pin 0             // This is for use with external decoding hardware
#define cw_decoder_audio_input_pin 0 // This is for audio detection decoding using OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR; this must be an analog pin!
#define cw_decoder_indicator 0       // Output - goes HIGH when cw tone is detected by OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR


#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  #define compression_detection_pin 0
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

#if defined(FEATURE_SLEEP)
  #define keyer_awake 0
#endif

#if defined(FEATURE_LCD_BACKLIGHT_AUTO_DIM)
  #define keyer_power_led 0   // must be a PWM-capable pin
#endif

#if defined(FEATURE_CAPACITIVE_PADDLE_PINS)
  #define capactive_paddle_pin_inhibit_pin 0     // if this pin is defined and is set high, the capacitive paddle pins will switch to normal (non-capacitive) sensing mode
#endif


// #if defined(FEATURE_PRESSURE_PADDLES)
// #define pressure_paddle_inhibit_pin 0     //  if set to 1 then physical paddles take precedence, pressure paddles ignored
// #endif


#ifdef FEATURE_4x4_KEYPAD
  #define Row3 0G
  #define Row2 0
  #define Row1 0
  #define Row0 0
  #define Col3 0
  #define Col2 0
  #define Col1 0
  #define Col0 0
#endif

#ifdef FEATURE_3x4_KEYPAD
  #define Row3 0
  #define Row2 0
  #define Row1 0
  #define Row0 0
  #define Col2 0
  #define Col1 0
  #define Col0 0
#endif

#ifdef FEATURE_SEQUENCER
  #define sequencer_1_pin 0
  #define sequencer_2_pin 0
  #define sequencer_3_pin 0
  #define sequencer_4_pin 0
  #define sequencer_5_pin 0
#endif //FEATURE_SEQUENCER

#define ptt_input_pin 0

#define tx_inhibit_pin 0
#define tx_pause_pin 0   

#define pin_sending_mode_automatic 0  // goes HIGH when keyer is sending code automatically
#define pin_sending_mode_manual 0     // goes HIGH when keyer is sending code manually (i.e. the paddle or straight key)

// pins to be defined according to availability, for kc4ifb pins 13,12,14,27 were used
 #ifdef FEATURE_PRESSURE_PADDLES
 #define LOADCELL_DOUT_PIN  13
 #define LOADCELL_SCK_PIN  12
 #define LOADCELL2_DOUT_PIN  14
 #define LOADCELL2_SCK_PIN  27
 #endif //FEATURE_PRESSURE_PADDLES





#else

  #error "Multiple pin_settings.h files included somehow..."

#endif //keyer_pin_settings_h

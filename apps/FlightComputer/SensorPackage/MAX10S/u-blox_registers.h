#pragma once

// Registers
const uint8_t UBX_SYNCH_1 = 0xB5;
const uint8_t UBX_SYNCH_2 = 0x62;

// The following are UBX Class IDs. Descriptions taken from ZED-F9P Interface Description Document page 32, NEO-M8P Interface Description page 145
const uint8_t UBX_CLASS_NAV = 0x01;  // Navigation Results Messages: Position, Speed, Time, Acceleration, Heading, DOP, SVs used
const uint8_t UBX_CLASS_RXM = 0x02;  // Receiver Manager Messages: Satellite Status, RTC Status
const uint8_t UBX_CLASS_INF = 0x04;  // Information Messages: Printf-Style Messages, with IDs such as Error, Warning, Notice
const uint8_t UBX_CLASS_ACK = 0x05;  // Ack/Nak Messages: Acknowledge or Reject messages to UBX-CFG input messages
const uint8_t UBX_CLASS_CFG = 0x06;  // Configuration Input Messages: Configure the receiver.
const uint8_t UBX_CLASS_UPD = 0x09;  // Firmware Update Messages: Memory/Flash erase/write, Reboot, Flash identification, etc.
const uint8_t UBX_CLASS_MON = 0x0A;  // Monitoring Messages: Communication Status, CPU Load, Stack Usage, Task Status
const uint8_t UBX_CLASS_AID = 0x0B;  //(NEO-M8P ONLY!!!) AssistNow Aiding Messages: Ephemeris, Almanac, other A-GPS data input
const uint8_t UBX_CLASS_TIM = 0x0D;  // Timing Messages: Time Pulse Output, Time Mark Results
const uint8_t UBX_CLASS_ESF = 0x10;  //(NEO-M8P ONLY!!!) External Sensor Fusion Messages: External Sensor Measurements and Status Information
const uint8_t UBX_CLASS_MGA = 0x13;  // Multiple GNSS Assistance Messages: Assistance data for various GNSS
const uint8_t UBX_CLASS_LOG = 0x21;  // Logging Messages: Log creation, deletion, info and retrieval
const uint8_t UBX_CLASS_SEC = 0x27;  // Security Feature Messages
const uint8_t UBX_CLASS_HNR = 0x28;  //(NEO-M8P ONLY!!!) High Rate Navigation Results Messages: High rate time, position speed, heading
const uint8_t UBX_CLASS_NMEA = 0xF0; // NMEA Strings: standard NMEA strings
const uint8_t UBX_CLASS_PUBX = 0xF1; // Proprietary NMEA-format messages defined by u-blox

// Class: CFG
// The following are used for configuration. Descriptions are from the ZED-F9P Interface Description pg 33-34 and NEO-M9N Interface Description pg 47-48
const uint8_t UBX_CFG_ANT = 0x13;       // Antenna Control Settings. Used to configure the antenna control settings
const uint8_t UBX_CFG_BATCH = 0x93;     // Get/set data batching configuration.
const uint8_t UBX_CFG_CFG = 0x09;       // Clear, Save, and Load Configurations. Used to save current configuration
const uint8_t UBX_CFG_DAT = 0x06;       // Set User-defined Datum or The currently defined Datum
const uint8_t UBX_CFG_DGNSS = 0x70;     // DGNSS configuration
const uint8_t UBX_CFG_ESFALG = 0x56;    // ESF alignment
const uint8_t UBX_CFG_ESFA = 0x4C;      // ESF accelerometer
const uint8_t UBX_CFG_ESFG = 0x4D;      // ESF gyro
const uint8_t UBX_CFG_GEOFENCE = 0x69;  // Geofencing configuration. Used to configure a geofence
const uint8_t UBX_CFG_GNSS = 0x3E;      // GNSS system configuration
const uint8_t UBX_CFG_HNR = 0x5C;       // High Navigation Rate
const uint8_t UBX_CFG_INF = 0x02;       // Depending on packet length, either: poll configuration for one protocol, or information message configuration
const uint8_t UBX_CFG_ITFM = 0x39;      // Jamming/Interference Monitor configuration
const uint8_t UBX_CFG_LOGFILTER = 0x47; // Data Logger Configuration
const uint8_t UBX_CFG_MSG = 0x01;       // Poll a message configuration, or Set Message Rate(s), or Set Message Rate
const uint8_t UBX_CFG_NAV5 = 0x24;      // Navigation Engine Settings. Used to configure the navigation engine including the dynamic model.
const uint8_t UBX_CFG_NAVX5 = 0x23;     // Navigation Engine Expert Settings
const uint8_t UBX_CFG_NMEA = 0x17;      // Extended NMEA protocol configuration V1
const uint8_t UBX_CFG_ODO = 0x1E;       // Odometer, Low-speed COG Engine Settings
const uint8_t UBX_CFG_PM2 = 0x3B;       // Extended power management configuration
const uint8_t UBX_CFG_PMS = 0x86;       // Power mode setup
const uint8_t UBX_CFG_PRT = 0x00;       // Used to configure port specifics. Polls the configuration for one I/O Port, or Port configuration for UART ports, or Port configuration for USB port, or Port configuration for SPI port, or Port configuration for DDC port
const uint8_t UBX_CFG_PWR = 0x57;       // Put receiver in a defined power state
const uint8_t UBX_CFG_RATE = 0x08;      // Navigation/Measurement Rate Settings. Used to set port baud rates.
const uint8_t UBX_CFG_RINV = 0x34;      // Contents of Remote Inventory
const uint8_t UBX_CFG_RST = 0x04;       // Reset Receiver / Clear Backup Data Structures. Used to reset device.
const uint8_t UBX_CFG_RXM = 0x11;       // RXM configuration
const uint8_t UBX_CFG_SBAS = 0x16;      // SBAS configuration
const uint8_t UBX_CFG_TMODE3 = 0x71;    // Time Mode Settings 3. Used to enable Survey In Mode
const uint8_t UBX_CFG_TP5 = 0x31;       // Time Pulse Parameters
const uint8_t UBX_CFG_USB = 0x1B;       // USB Configuration
const uint8_t UBX_CFG_VALDEL = 0x8C;    // Used for config of higher version u-blox modules (ie protocol v27 and above). Deletes values corresponding to provided keys/ provided keys with a transaction
const uint8_t UBX_CFG_VALGET = 0x8B;    // Used for config of higher version u-blox modules (ie protocol v27 and above). Configuration Items
const uint8_t UBX_CFG_VALSET = 0x8A;    // Used for config of higher version u-blox modules (ie protocol v27 and above). Sets values corresponding to provided key-value pairs/ provided key-value pairs within a transaction.

// Class: NMEA
// The following are used to enable NMEA messages. Descriptions come from the NMEA messages overview in the ZED-F9P Interface Description
const uint8_t UBX_NMEA_MSB = 0xF0; // All NMEA enable commands have 0xF0 as MSB. Equal to UBX_CLASS_NMEA
const uint8_t UBX_NMEA_DTM = 0x0A; // GxDTM (datum reference)
const uint8_t UBX_NMEA_GAQ = 0x45; // GxGAQ (poll a standard message (if the current talker ID is GA))
const uint8_t UBX_NMEA_GBQ = 0x44; // GxGBQ (poll a standard message (if the current Talker ID is GB))
const uint8_t UBX_NMEA_GBS = 0x09; // GxGBS (GNSS satellite fault detection)
const uint8_t UBX_NMEA_GGA = 0x00; // GxGGA (Global positioning system fix data)
const uint8_t UBX_NMEA_GLL = 0x01; // GxGLL (latitude and long, whith time of position fix and status)
const uint8_t UBX_NMEA_GLQ = 0x43; // GxGLQ (poll a standard message (if the current Talker ID is GL))
const uint8_t UBX_NMEA_GNQ = 0x42; // GxGNQ (poll a standard message (if the current Talker ID is GN))
const uint8_t UBX_NMEA_GNS = 0x0D; // GxGNS (GNSS fix data)
const uint8_t UBX_NMEA_GPQ = 0x40; // GxGPQ (poll a standard message (if the current Talker ID is GP))
const uint8_t UBX_NMEA_GQQ = 0x47; // GxGQQ (poll a standard message (if the current Talker ID is GQ))
const uint8_t UBX_NMEA_GRS = 0x06; // GxGRS (GNSS range residuals)
const uint8_t UBX_NMEA_GSA = 0x02; // GxGSA (GNSS DOP and Active satellites)
const uint8_t UBX_NMEA_GST = 0x07; // GxGST (GNSS Pseudo Range Error Statistics)
const uint8_t UBX_NMEA_GSV = 0x03; // GxGSV (GNSS satellites in view)
const uint8_t UBX_NMEA_RLM = 0x0B; // GxRMC (Return link message (RLM))
const uint8_t UBX_NMEA_RMC = 0x04; // GxRMC (Recommended minimum data)
const uint8_t UBX_NMEA_TXT = 0x41; // GxTXT (text transmission)
const uint8_t UBX_NMEA_VLW = 0x0F; // GxVLW (dual ground/water distance)
const uint8_t UBX_NMEA_VTG = 0x05; // GxVTG (course over ground and Ground speed)
const uint8_t UBX_NMEA_ZDA = 0x08; // GxZDA (Time and Date)

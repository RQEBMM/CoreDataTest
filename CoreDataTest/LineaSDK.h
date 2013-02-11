/** @defgroup G_LINEA Linea SDK
 Provides access to Linea device series.
 In order to use Linea in your program, several steps have to be performed:
 - Include LineaSDK.h and libdtdev.a in your project.
 - Go to Frameworks and add ExternalAccessory framework
 - Edit your program plist file, add new element and select "Supported external accessory protocols" from the list, then add two items to it -
 com.datecs.linea.pro.msr and com.datecs.linea.pro.bar
 @{
 */

#define buttonPressed lineaButtonPressed
#define buttonReleased lineaButtonReleased

#ifndef __has_feature         // Optional of course.
#define __has_feature(x) 0  // Compatibility with non-clang compilers.
#endif

#ifndef BARCODES_DEFINED
#define BARCODES_DEFINED
typedef enum {
	BAR_ALL=0, 
	BAR_UPC,
	BAR_CODABAR,
	BAR_CODE25_NI2OF5,
	BAR_CODE25_I2OF5,
	BAR_CODE39,
	BAR_CODE93,
	BAR_CODE128,
	BAR_CODE11,
	BAR_CPCBINARY,
	BAR_DUN14,
	BAR_EAN2,
	BAR_EAN5,
	BAR_EAN8,
	BAR_EAN13,
	BAR_EAN128,
	BAR_GS1DATABAR,
	BAR_ITF14,
	BAR_LATENT_IMAGE,
	BAR_PHARMACODE,
	BAR_PLANET,
	BAR_POSTNET,
	BAR_INTELLIGENT_MAIL,
	BAR_MSI,
	BAR_POSTBAR,
	BAR_RM4SCC,
	BAR_TELEPEN,
	BAR_PLESSEY,
	BAR_PDF417,
	BAR_MICROPDF417,
	BAR_DATAMATRIX,
	BAR_AZTEK,
	BAR_QRCODE,
	BAR_MAXICODE,
	BAR_LAST
}BARCODES;

typedef enum {
	BAR_EX_ALL=0, 
	BAR_EX_UPCA,
	BAR_EX_CODABAR,
	BAR_EX_CODE25_NI2OF5,
	BAR_EX_CODE25_I2OF5,
	BAR_EX_CODE39,
	BAR_EX_CODE93,
	BAR_EX_CODE128,
	BAR_EX_CODE11,
	BAR_EX_CPCBINARY,
	BAR_EX_DUN14,
	BAR_EX_EAN2,
	BAR_EX_EAN5,
	BAR_EX_EAN8,
	BAR_EX_EAN13,
	BAR_EX_EAN128,
	BAR_EX_GS1DATABAR,
	BAR_EX_ITF14,
	BAR_EX_LATENT_IMAGE,
	BAR_EX_PHARMACODE,
	BAR_EX_PLANET,
	BAR_EX_POSTNET,
	BAR_EX_INTELLIGENT_MAIL,
	BAR_EX_MSI_PLESSEY,
	BAR_EX_POSTBAR,
	BAR_EX_RM4SCC,
	BAR_EX_TELEPEN,
	BAR_EX_UK_PLESSEY,
	BAR_EX_PDF417,
	BAR_EX_MICROPDF417,
	BAR_EX_DATAMATRIX,
	BAR_EX_AZTEK,
	BAR_EX_QRCODE,
	BAR_EX_MAXICODE,
	BAR_EX_RESERVED1,
	BAR_EX_RESERVED2,
	BAR_EX_RESERVED3,
	BAR_EX_RESERVED4,
	BAR_EX_RESERVED5,
	BAR_EX_UPCA_2,
	BAR_EX_UPCA_5,
	BAR_EX_UPCE,
	BAR_EX_UPCE_2,
	BAR_EX_UPCE_5,
	BAR_EX_EAN13_2,
	BAR_EX_EAN13_5,
	BAR_EX_EAN8_2,
	BAR_EX_EAN8_5,
	BAR_EX_CODE39_FULL,
	BAR_EX_ITA_PHARMA,
	BAR_EX_CODABAR_ABC,
	BAR_EX_CODABAR_CX,
	BAR_EX_SCODE,
	BAR_EX_MATRIX_2OF5,
	BAR_EX_IATA,
	BAR_EX_KOREAN_POSTAL,
	BAR_EX_CCA,
	BAR_EX_CCB,
	BAR_EX_CCC,
	BAR_EX_LAST
}BARCODES_EX;
#endif

#if !__has_feature(objc_arc)
#ifndef FINANCIALCARD_DEFINED
#define FINANCIALCARD_DEFINED
typedef struct
{
    NSString *accountNumber;
    NSString *cardholderName;
    int  expirationYear;
    int  expirationMonth;
    NSString *serviceCode;
    NSString *discretionaryData;
    NSString *firstName;
    NSString *lastName;
}financialCard; 
#endif
#endif

/**
 * Connection state
 */
#ifndef CONNSTATES_DEFINED
#define CONNSTATES_DEFINED
typedef enum {
	CONN_DISCONNECTED=0,
	CONN_CONNECTING,
	CONN_CONNECTED
}CONN_STATES;
#endif

typedef enum {
	MODE_SINGLE_SCAN=0,
	MODE_MULTI_SCAN
}SCAN_MODES;

typedef enum {
	BUTTON_DISABLED=0,
	BUTTON_ENABLED
}BUTTON_STATES;

typedef enum {
	MS_PROCESSED_CARD_DATA=0,
	MS_RAW_CARD_DATA
}MS_MODES;

typedef enum {
	BARCODE_TYPE_DEFAULT=0,
	BARCODE_TYPE_EXTENDED
}BT_MODES;

typedef enum {
	UPDATE_INIT=0,
	UPDATE_ERASE,
    UPDATE_WRITE,
    UPDATE_FINISH
}UPDATE_PHASES;

/*******************************************************************************
 * MIFARE STATUS CODES
 *******************************************************************************/ 
#define MF_STAT_OK				-0
#define MF_STAT_TIMEOUT			-1
#define MF_STAT_COLLISION		-2
#define MF_STAT_PARITY_ERROR	-3
#define MF_STAT_FRAMING_ERROR	-4
#define MF_STAT_CRC_ERROR		-5 
#define MF_STAT_FIFO_OVERFLOW	-6
#define MF_STAT_EEPROM_ERROR	-7
#define MF_STAT_INVALID_KEY		-8
#define MF_STAT_UNKNOWN_ERROR	-9
#define MF_STAT_AUTH_ERROR		-10
#define MF_STAT_CODE_ERROR		-11
#define MF_STAT_BITCOUNT_ERROR	-12
#define MF_STAT_NOT_AUTH		-13
#define MF_STAT_VALUE_ERROR		-14

/*******************************************************************************
 * MIFARE VALUE OPERATIONS
 *******************************************************************************/ 
#define MF_OPERATION_INCREMENT	0xC0
#define MF_OPERATION_DECREMENT	0xC1
#define MF_OPERATION_RESTORE	0xC2

/* Encryptions */
#define ALG_AES256				0

/**
 Authentication key
 */
#define KEY_AUTHENTICATION 0
/**
 Encryption key, if set magnetic card data will be encrypted
 */
#define KEY_ENCRYPTION 1


#if !__has_feature(objc_arc)
#ifndef FIRMWAREINFO_DEFINED
typedef struct firmwareInfo
{
	NSString *deviceName;
	NSString *deviceModel;
	NSString *firmwareRevision;
	int		  firmwareRevisionNumber;
}firmwareInfo;
#endif
#endif



/**
 Protocol describing various notifications that LineaSDK can send.
 @ingroup G_LINEA
 */
@protocol LineaDelegate
@optional
/** @defgroup G_LNDELEGATE Delegate Notifications
 @ingroup G_LINEA
 Notifications sent by the sdk on various events - barcode scanned, magnetic card data, communication status, etc
 @{
 */

/**
 Notifies about the current connection state
 @param state - connection state, one of:
 <table>
 <tr><td>CONN_DISCONNECTED</td><td>there is no connection to Linea and the sdk will not try to make one even if the device is attached</td></tr>
 <tr><td>CONN_CONNECTING</td><td>Linea is not currently connected, but the sdk is actively trying to</td></tr>
 <tr><td>CONN_CONNECTED</td><td>Linea is connected</td></tr>
 </table>
 **/
-(void)connectionState:(int)state;

/**
 Notification sent when some of the Linea's buttons is pressed
 @param which button identifier, one of:
 <table>
 <tr><td>0</td><td>right scan button</td></tr>
 </table>
 **/
-(void)buttonPressed:(int)which;

/**
 Notification sent when some of the Linea's buttons is released
 @param which button identifier, one of:
 <table>
 <tr><td>0</td><td>right scan button</td></tr>
 </table>
 **/
-(void)buttonReleased:(int)which;

/**
 Notification sent when barcode is successfuly read
 @param barcode - string containing barcode data
 @param type - barcode type, one of the BAR_* constants
 **/
-(void)barcodeData:(NSString *)barcode type:(int)type;

/**
 Notification sent when magnetic card is successfuly read
 @param track1 - data contained in track 1 of the magnetic card or nil
 @param track2 - data contained in track 2 of the magnetic card or nil
 @param track3 - data contained in track 3 of the magnetic card or nil
 **/
-(void)magneticCardData:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3;

/**
 Notification sent when magnetic card is successfuly read
 @param tracks contains the raw magnetic card data. These are the bits directly from the magnetic head.
 The maximum length of a single track is 704 bits (88 bytes), so the command returns the 3 tracks as 3x88 bytes block
 **/
-(void)magneticCardRawData:(NSData *)tracks;

/**
 Notification sent when magnetic card is successfuly. The data is encrypted via the selected encryption algorithm.
 
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the
 tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 
 In the more secure way, where the decryption key resides in a server only, the card read process will look something like:
 - (User) swipes the card 
 - (iOS program) receives the data via magneticCardEncryptedData and sends to the server
 - (iOS program)[optional] sends current Linea serial number along with the data received from magneticCardEncryptedData. This can
 be used for data origin verification
 - (Server) decrypts the data, extracts all the information from the fields
 - (Server)[optional] if the ipod program have sent the Linea serial number before, the server compares the received serial number
 with the one that's inside the encrypted block 
 - (Server) checks if the card data is the correct one, i.e. all needed tracks are present, card is the same type as required, etc
 and sends back notification to the ipod program. 
 @param encryption encryption algorithm used, one of:
 <table>
 <tr><td>0</td><td>AES 256</td></tr>
 </table>
 @param data contains the encrypted card data
 **/
-(void)magneticCardEncryptedData:(int)encryption data:(NSData *)data;

/**
 Notification sent when magnetic card is successfuly. The data is encrypted via the selected encryption algorithm.
 
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the
 tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 
 In the more secure way, where the decryption key resides in a server only, the card read process will look something like:
 - (User) swipes the card 
 - (iOS program) receives the data via magneticCardEncryptedData and sends to the server
 - (iOS program)[optional] sends current Linea serial number along with the data received from magneticCardEncryptedData. This can
 be used for data origin verification
 - (Server) decrypts the data, extracts all the information from the fields
 - (Server)[optional] if the ipod program have sent the Linea serial number before, the server compares the received serial number
 with the one that's inside the encrypted block 
 - (Server) checks if the card data is the correct one, i.e. all needed tracks are present, card is the same type as required, etc
 and sends back notification to the ipod program. 
 @param encryption encryption algorithm used, one of:
 <table>
 <tr><td>0</td><td>AES 256</td></tr>
 </table>
 @param tracks contain information which tracks are successfully read and inside the encrypted data as bit fields, bit 1 corresponds to track 1, etc, so value of 7 means all tracks are read
 @param data contains the encrypted card data
 **/
-(void)magneticCardEncryptedData:(int)encryption tracks:(int)tracks data:(NSData *)data;

/**
 Notification sent when magnetic card is successfuly read. The raw card data is encrypted via the selected encryption algorithm.
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Track data: the maximum length of a single track is 704 bits (88 bytes), so track data contains 3x88 bytes
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data.
 The data block is rounded to 16 bytes
 @param encryption encryption algorithm used, one of:
 <table>
 <tr><td>0</td><td>AES 256</td></tr>
 </table>
 @param data - Contains the encrypted raw card data
 **/
-(void)magneticCardEncryptedRawData:(int)encryption data:(NSData *)data;

/**
 Notification sent when firmware update process advances. Do not call any linea functions until firmware update is complete!
 During the firmware update notifications will be posted.
 @param phase update phase, one of:
 <table>
 <tr><td>UPDATE_INIT</td><td>Initializing firmware update</td></tr>
 <tr><td>UPDATE_ERASE</td><td>Erasing flash memory</td></tr>
 <tr><td>UPDATE_WRITE</td><td>Writing data</td></tr>
 <tr><td>UPDATE_FINISH</td><td>Update complete</td></tr>
 </table>
 @param percent firmware update progress in percents
 **/
-(void)firmwareUpdateProgress:(int)phase percent:(int)percent;

/**
 Notification sent when bluetooth discovery finds new bluetooth device
 @param success true if the discovery complete successfully, even if it not resulted in any device found, false if there was some error
 communicating with the bluetooth module
 **/
-(void)bluetoothDiscoverComplete:(BOOL)success;

/**
 Notification sent when bluetooth discovery finds new bluetooth device
 @param btAddress bluetooth address of the device
 @param btName bluetooth name of the device
 **/
-(void)bluetoothDeviceDiscovered:(NSString *)btAddress name:(NSString *)btName;


/**
 Notification sent when JIS I & II magnetic card is successfuly read
 @param data - data contained in the magnetic card
 **/
-(void)magneticJISCardData:(NSString *)data;
/**@}*/

@end

/**
 Provides access to Linea functions.
 */
@interface Linea : NSObject

/** @defgroup G_LNGENERAL General functions
 @ingroup G_LINEA
 Functions to connect/disconnect, set delegate, make sounds, update firmware, control various device settings
 @{
 */

/**
 Creates and initializes new Linea class instance or returns already initalized one. Use this function, if you want to access the class from different places
 @return shared class instance
 **/
+(id)sharedDevice;

/**
 Allows unlimited delegates to be added to a single class instance. This is useful in the case of global
 class and every view can use addDelegate when the view is shown and removeDelegate when no longer needs to monitor events
 @param newDelegate the delegate that will be notified of Linea events
 **/
-(void)addDelegate:(id)newDelegate;

/**
 Removes delegate, previously added with addDelegate
 @param newDelegate the delegate that will be no longer be notified of Linea events
 **/
-(void)removeDelegate:(id)newDelegate;

/**
 Tries to connect to Linea in the background, connection status notifications will be passed through the delegate.
 Once connect is called, it will automatically try to reconnect until disconnect is called.
 Note that "connect" call works in background and will notify the caller of connection success via connectionState
 delegate. Do not assume the library has fully connected to the device after this call, but wait for the notification.
 **/
-(void)connect;

/**
 Stops the sdk from trying to connect to Linea and breaks existing connection.
 **/
-(void)disconnect;

/**
 Returns Linea's battery capacity in percent
 @note Reading battery voltages during charging (both Linea charing and Linea charging the iPod) is unreliable!
 @return Battery capacity in percent
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getBatteryCapacity;

/**
 Returns Linea's battery voltage
 @note Reading battery voltages during charging (both Linea charing and Linea charging the iPod) is unreliable!
 @return Battery voltage in Volt*10, i.e. value of 45 means 4.5V
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getBatteryVoltage;

/**
 Makes Linea plays a sound using the built-in speaker
 @param volume controls the volume (0-100). Currently have no effect
 @param data an array of integer values specifying pairs of tone(Hz) and duration(ms).
 @param length length in bytes of beepData array
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 @note A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz
 will look int beepData[]={2000,400,5000,400}
 */
-(void)playSound:(int)volume beepData:(int *)data length:(int)length;

/**
 Returns if Linea is charging the iOS device from it's own battery. Linea firmware versions prior to 2.13 will return true
 if external charge is attached, 2.13 and later will return only if Linea's own battery is used for charging
 @return TRUE if charging is enabled.
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(BOOL)getCharging;

/**
 Enables or disables Lines's capability to charge the handheld from it's own battery. Charging can stop if Linea's battery goes too low.
 When enabling or disabling the charge linea will force disconnect and reconnect.
 
 <br>While Linea can act as external battery for the iPod/iPhone, there are certain limitations if you decide to implement it. The internal battery is
 not big enough, so if the iPod/iPhone consumes a lot of power from it, it will go down very fast and force the firmware to cut the charge to prevent
 going down to dangerous levels. The proper use of this charging function depends on how the program, running on the iPod/iPhone, is used and how the
 iPod/iPhone is discharged
 
 <br>There are two possible ways to use Linea's charge:
 - Emergency mode - in the case iPod/iPhone usage is designed in a way it will last long enough between charging sessions and using Linea's charge
 is not generally needed, the charge can be used if the iPod/iPhone for some reason goes too low (like <50%), so it is given some power to continue
 working until next charging. An example will be store, where devices are being charged every night, but extreme usage on some iPod drains
 the battery before the end of the shift.
 This is the less efficient way to charge it, also, Linea will refuse to start the charge if it's own battery goes below 3.8v, so depending on the usage,
 barcode type and if the barcode engine is set to work all the time, it may not be possible to start the charge.

 - Max life mode - it is the case where both devices are required to operate as long as possible. Usually, the iPod/iPhone's battery will be drained
 way faster than Linea's, especially with wifi enabled programs and to keep both devices operating as long as possible, the charging should
 be desinged in a way so iPod/iPhone is able to use most of Linea's battery. This is possible, if you start charging when iPod/iPhone is almost full - at around
 75-80% or higher. This way the iPod will consume small amount of energy, allowing our battery to slowly be used almost
 fully to charge it.
 
 <br>LineaDemo application contains sample implementation of max life mode charging.
 
 @note Reading battery voltages during charging is unreliable!
 @param enabled TRUE to enable charging, FALSE to disable/stop it
 @return TRUE if operation succeeded. Enabling charge can fail if Linea's battery is low. Disabling charge will fail if there is external charger or usb cable attached.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)setCharging:(BOOL)enabled;

/**
 @deprecated
 Returns information about the specified firmware file. Based on it, and the connected Linea's name, model and firmware version
 you can chose to update or not the Linea's firmware
 @param path the full path and file name where the firmware file is located
 @param info pointer to a structure, that will be filled with firmware file information - name, model and firmware version
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
#if !__has_feature(objc_arc)
-(void)getFirmwareFileInformation:(NSString *)path firmwareInfo:(struct firmwareInfo *)info;
#endif

/**
 Returns information about the specified firmware data. Based on it, and the connected Linea's name, model and firmware version
 you can chose to update or not the Linea's firmware
 @param data - firmware data
 @return dictionary containing extracted data or nil if the data is invalid. Keys contained are:
 <table>
 <tr><td>"deviceName"</td><td>Device name, for example "Linea"</td></tr>
 <tr><td>"deviceModel"</td><td>Device model, for example "XBAMBL</td></tr>
 <tr><td>"firmwareRevision"</td><td>Firmware revision as string, for example 2.41</td></tr>
 <tr><td>"firmwareRevisionNumber"</td><td>Firmware revision as number MAJOR*100+MINOR, i.e. 2.41 will be returned as 241</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 **/
-(NSDictionary *)getFirmwareFileInformation:(NSData *)data;

/**
 Updates Linea's firmware with specified firmware file. The firmware can only be upgraded or downgraded, if you send
 the same firmware version, then no update process will be started.
 @param path the full path and file name where the firmware file is located
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if the firmware file is missing, can't be opened, damaged or contains invalid firmware version
 @note Make sure the user does not interrupt the process or the device will be rendered unusable and can only be recovered via
 the special firmware update cable
 */
-(void)updateFirmware:(NSString *)path;

/**
 Updates Linea's firmware with specified firmware data. The firmware can only be upgraded or downgraded, if you send
 the same firmware version, then no update process will be started.
 @param data the firmware data
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if the firmware file is missing, can't be opened, damaged or contains invalid firmware version
 @note Make sure the user does not interrupt the process or the device will be rendered unusable and can only be recovered via
 the special firmware update cable
 */
-(void)updateFirmwareData:(NSData *)data;

/**
 Returns the current sync button mode. See setSyncButtonMode for more detailed description.
 This setting is stored into flash memory and will persist.
 @return sync button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Linea's will not perform synchronization when you press and hold the button for 3 seconds</td></tr>
 <tr><td>BUTTON_ENABLED</td><td>Linea's will perform synchronization when you press and hold the button for 3 seconds</td></tr>
 </table>
 @note Although this function was made for Linea 1, that had hardware button to enter sync mode, it still works for enabling/disabling automated sync on Linea 4 and onward
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getSyncButtonMode;

/**
 Sets Linea's sync button mode.
 This setting is stored into flash memory and will persist.
 @param mode button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Linea's will not perform synchronization when you press and hold the button for 3 seconds</td></tr>
 <tr><td>BUTTON_ENABLED (default)</td><td>Linea's will perform synchronization when you press and hold the button for 3 seconds</td></tr>
 </table>
 @note Although this function was made for Linea 1, that had hardware button to enter sync mode, it still works for enabling/disabling automated sync on Linea 4 and onward
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)setSyncButtonMode:(int)mode;
/**@}*/



/** @defgroup G_LNMSREADER Magnetic Stripe Reader Functions
 Functions to work with the Linea's built-in magenetic card reader
 @ingroup G_LINEA
 @{
 */

/**
 Enables reading of magnetic cards. Whenever a card is successfully read, the magneticCardData delegate will be called.
 Current magnetic card heads used in Linea 1.0, 1.5 and 2.0 consume so little power, that there is no drawback in leaving
 scanning enabled all the time.
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)msStartScan;

/**
 Disables magnetic card scanning started with msStartScan
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)msStopScan;

 /**
 @deprecated
 Helper function to parse financial card and extract the data - name, number, expiration date.
 The function will extract as much information as possible, fields not found will be set to nil/0.
 @param data - pointer to financialCard structure, where the extracted data will be stored
 @param track1 - track1 information or nil
 @param track2 - track2 information or nil
 @return TRUE if the card tracks represent valid financial card and data was extracted
 @throw NSPortTimeoutException if there is no connection to Linea
 **/
#if !__has_feature(objc_arc)
-(BOOL)msProcessFinancialCard:(financialCard *)data track1:(NSString *)track1 track2:(NSString *)track2;
#endif

/**
 Helper function to parse financial card and extract the data - name, number, expiration date.
 The function will extract as much information as possible.
 @param track1 - track1 information or nil
 @param track2 - track2 information or nil
 @return dictionary containing extracted data or nil if the data is invalid. Keys contained are:
 <table>
 <tr><td>"accountNumber"</td><td>Account number</td></tr>
 <tr><td>"cardholderName"</td><td>Cardholder name, as stored in the card</td></tr>
 <tr><td>"expirationYear"</td><td>Expiration date - year</td></tr>
 <tr><td>"expirationMonth"</td><td>Expiration date - month</td></tr>
 <tr><td>"serviceCode"</td><td>Service code (if any)</td></tr>
 <tr><td>"discretionaryData"</td><td>Discretionary data (if any)</td></tr>
 <tr><td>"firstName"</td><td>Extracted cardholder's first name</td></tr>
 <tr><td>"lastName"</td><td>Extracted cardholder's last name</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 **/
-(NSDictionary *)msProcessFinancialCard:(NSString *)track1 track2:(NSString *)track2;

/**
 Returns the current magnetic card data mode.
 This setting is not persistent and is best to configure it upon connect.
 @return card data mode, one of the:
 <table>
 <tr><td>MS_PROCESSED_CARD_DATA</td><td>Card data will be processed and will be returned via call to magneticCardData</td></tr>
 <tr><td>MS_RAW_CARD_DATA</td><td>Card data will not be processed and will be returned via call to magneticCardRawData</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getMSCardDataMode;

/**
 Sets Linea's magnetic card data mode. 
 This setting is not persistent and is best to configure it upon connect.
 @param mode magnetic card data mode:
 <table>
 <tr><td>MS_PROCESSED_CARD_DATA</td><td>Card data will be processed and will be returned via call to magneticCardData</td></tr>
 <tr><td>MS_RAW_CARD_DATA</td><td>Card data will not be processed and will be returned via call to magneticCardRawData</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)setMSCardDataMode:(int)mode;
/**@}*/



/** @defgroup G_LNBARCODEREADER Barcode Reader Functions
 Functions for scanning barcodes, various barcode settings and direct control of the barcode engine
 @ingroup G_LINEA
 @{
 */
 
/**
 Helper function to return string name of barcode type
 @param barcodeType barcode type returned from scanBarcode
 @return barcode type name
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(NSString *)barcodeType2Text:(int)barcodeType;

/**
 Starts barcode engine.
 In single scan mode the laser will be on until barcode is successfully read, the timeout elapses
 (set via call to setScanTimeout) or if stopScan is called.
 In multi scan mode the laser will stay on even if barcode is successfully read allowing series of
 barcodes to be scanned within a single read session. The scanning will stop if no barcode is scanned
 in the timeout interval (set via call to setScanTimeout) or if stopScan is called.
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)startScan;
	
/**
 Stops ongoing scan started with startScan
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)stopScan;

/**
 Returns the current scan timeout. See setScanTimeout for more detailed description.
 This setting is not persistent and is best to configure it upon connect.
 @return scan timeout in seconds
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getScanTimeout;

/**
 Sets the scan timeout. This it the max time that the laser will be on in
 single scan mode, or the time without scanning that will force the laser off in multi scan mode.
 This setting is not persistent and is best to configure it upon connect.
 @param timeout barcode engine timeout in seconds [1-60] or 0 to disable timeout. Default is 0
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)setScanTimeout:(int)timeout;

/**
 Returns the current scan button mode. See setScanButtonMode for more detailed description.
 This setting is not persistent and is best to configure it upon connect.
 @return scan button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Linea's button will become inactive</td></tr>
 <tr><td>BUTTON_ENABLED</td><td>Linea's button will triger barcode scan when pressed</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getScanButtonMode;

/**
 Sets Linea's scan button mode.
 This setting is not persistent and is best to configure it upon connect.
 @param mode button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Linea's button will become inactive</td></tr>
 <tr><td>BUTTON_ENABLED</td><td>Linea's button will triger barcode scan when pressed</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)setScanButtonMode:(int)mode;

/**
 Sets Linea's beep, which is used upon successful barcode scan
 This setting is not persistent and is best to configure it upon connect.
 @param enabled turns on or off beeping
 @param volume controls the volume (0-100). Currently have no effect
 @param data an array of integer values specifying pairs of tone(Hz) and duration(ms).
 @param length length in bytes of beepData array
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 @note  A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz will look int beepData[]={2000,400,5000,400}
*/
-(void)setScanBeep:(BOOL)enabled volume:(int)volume beepData:(int *)data length:(int)length;

/**
 Returns the current scan mode.
 This setting is not persistent and is best to configure it upon connect.
 @return scanning mode, one of the:
 <table>
 <tr><td>MODE_SINGLE_SCAN</td><td>Linea will deactivate the laser after a successful barcode scan</td></tr>
 <tr><td>MODE_MULTI_SCAN</td><td>Linea will continue to scan even after successful barcode scan and will stop when scan button is released, stopScan command is sent or there is no barcode scaned for several seconds (set via call to setScanTimeout)</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getScanMode;

/**
 Sets Linea's scan button mode.
 This setting is not persistent and is best to configure it upon connect.
 @param mode scanning mode, one of the:
 <table>
 <tr><td>MODE_SINGLE_SCAN</td><td>Linea will deactivate the laser after a successful barcode scan</td></tr>
 <tr><td>MODE_MULTI_SCAN</td><td>Linea will continue to scan even after successful barcode scan and will stop when scan button is released, stopScan command is sent or there is no barcode scaned for several seconds (set via call to setScanTimeout)</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)setScanMode:(int)mode;

/**
 Enables or disables reading of specific barcode type.
 This setting is stored into the flash memory and will persists.
 @param barcodeType barcode type, one of the BAR_* constants with the exception of BAR_LAST. You can use BAR_ALL to enable or disable all barcode types at once
 @param enabled enables or disables reading of that barcode type
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)enableBarcode:(int)barcodeType enabled:(BOOL)enabled;

/**
 Returns if the the engine is set to read the barcode type or not.
 @param type barcode type, one of the BAR_* constants with the exception of BAR_ALL and BAR_LAST
 @return TRUE if the barcode is enabled
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)isBarcodeEnabled:(int)type;

/**
 Returns if the the engine can read the barcode type or not.
 @param type barcode type, one of the BAR_* constants with the exception of BAR_ALL and BAR_LAST
 @return TRUE if the barcode is supported
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)isBarcodeSupported:(int)type;

/**
 Returns the current barcode type mode. See setBarcodeTypeMode for more detailed description.
 This setting will not persists.
 @return barcode type mode, one of the:
 <table>
 <tr><td>BARCODE_TYPE_DEFAULT</td><td>default barcode types, listed in BARCODES enumeration</td></tr>
 <tr><td>BARCODE_TYPE_EXTENDED</td><td>extended barcode types, listed in BARCODES_EX enumeration</td></tr>
 </table>
 @note Although this function was made for Linea 1, that had hardware button to enter sync mode, it still works for enabling/disabling automated sync on Linea 4 and onward
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)getBarcodeTypeMode;

/**
 Sets barcode type mode. Linea can return barcode type from the default list (listed in BARCODES)
 or extended one (listed in BARCODES_EX). The extended one is superset to the default, so current
 programs will be mostly unaffected if they switch from default to extended (with the exception of
 barcodes like UPC-A and UPC-E, which will be returned as UPC in the default list, but proper types
 in the extended. This setting will not persists.
 @param mode barcode type mode, one of the:
 <table>
 <tr><td>BARCODE_TYPE_DEFAULT (default)</td><td>default barcode types, listed in BARCODES enumeration</td></tr>
 <tr><td>BARCODE_TYPE_EXTENDED</td><td>extended barcode types, listed in BARCODES_EX enumeration</td></tr>
 </table>
 @note Although this function was made for Linea 1, that had hardware button to enter sync mode, it still works for enabling/disabling automated sync on Linea 4 and onward
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)setBarcodeTypeMode:(int)mode;
 
 /**
 Sends data directly to the barcode engine. Use this function with EXTREME care, you can easily render
 your barcode engine useless.
 Refer to the barcode engine documentation on supported commands
 @param data command buffer
 @param length the number of bytes in data buffer
 @return TRUE if write operation succeeded
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)barcodeEngineWrite:(void *)data length:(int)length;

/**
 Sends data directly to the barcode engine. Use this function with EXTREME care, you can easily render
 your barcode engine useless.
 Refer to the barcode engine documentation on supported commands
 @param data command string
 @return TRUE if write operation succeeded
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)barcodeEngineWrite:(NSString *)data;

/**
 Reads a response from the barcode engine.
 Refer to the barcode engine documentation on supported commands
 @param data buffer, where the response will be stored
 @param length the maximum number of bytes to store in length buffer
 @param timeout the number of seconds to wait for response
 @return number of bytes actually read
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(int)barcodeEngineRead:(void *)data length:(int)length timeout:(double)timeout;

/**
 Allows basic control over the power to the barcode engine. By default Linea manages barcode engine by turning
 it on when scan operation is needed, then turning off after 5 seconds of inactivity. There are situations, where
 barcode engine should stay on to give better user experience, namely when using 2D barcode engine, which takes 1.7 seconds
 to start. This function is ignored for 1D barcode engines.

 <br>Be cautious using this function, if you pass TRUE to engineOn, the barcode engine will not turn off unless Linea is disconnected,
 program closes connection or iPod/iPhone goes to sleep, so it can drain the battery if left for 10+ hours on.
 This setting does not persist, it is valid for current session only.
 @param engineOn TRUE will keep the engine powered on until the function is called with FALSE. In case of FALSE, Linea will work the usual way -
 powers on the engine just before scan operation. 
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)barcodeEnginePowerControl:(BOOL)engineOn;

/**
 Allows for a custom initialization string to be sent to the barcode. The string is sent directly, if the barcode is currently
 powered on, and every time it gets initialized. The setting does not persists, so it is best this command is called upon new connection
 with Linea
 @param data barcode engine initialization data (consult barcode engine manual)
 @return TRUE if the operation was successful
 @throw NSPortTimeoutException if there is no connection to Linea
 **/
-(BOOL)barcodeEngineSetInitString:(NSString *)data;

/**
 Returns the current custom init string, or an empty string if none
 @throw NSPortTimeoutException if there is no connection to Linea
 **/
-(NSString *)barcodeEngineGetInitString;

/**
 Sends configuration parameters directly to the opticon barcode engine. Use this function with EXTREME care,
 you can easily render your barcode engine useless. Refer to the barcode engine documentation on supported commands.
 <br>The function encapsulates the data with the ESC and CR so you don't have to send them. It optionally sends Z2
 after the command to ensure settings are stored in the flash.
 <br>You can send multiple parameters with a single call if you format them as follows:
 - commands that take 2 symbols can be sent without any delimiters, like: "C1C2C3"
 - commands that take 3 symbols should be prefixed by [, like: "C1[C2AC3" (in this case commands are C1, C2A and C3
 - commands that take 4 symbols should be prefixed by ], like: "C1C2]C3AB" (in this case commands are C1, C2 and C3AB
 @param data command string
 @param saveToFlash if TRUE, command also saves the settings to flash. Saving setting is slower, so should be in ideal
 case executed only once and the program to remember it. The scanner's power usually gets cut when Linea goes to sleep - 
 5 seconds of idle time, so any non-stored to flash settings are lost, but if barcodeEnginePowerControl:TRUE is used on
 2D engine, then even non-saved to flash settings will persist until device disconnects (iOS goes to sleep, physical disconnect)
 @return TRUE if operation was successful
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)barcodeOpticonSetParams:(NSString *)data saveToFlash:(BOOL)saveToFlash;

/**
 Sends configuration parameters directly to the opticon barcode engine. Use this function with EXTREME care,
 you can easily render your barcode engine useless. Refer to the barcode engine documentation on supported commands.
 <br>The function encapsulates the data with the ESC and CR so you don't have to send them. It sends Z2
 after the command to ensure settings are stored in the flash.
 <br>You can send multiple parameters with a single call if you format them as follows:
 - commands that take 2 symbols can be sent without any delimiters, like: "C1C2C3"
 - commands that take 3 symbols should be prefixed by [, like: "C1[C2AC3" (in this case commands are C1, C2A and C3
 - commands that take 4 symbols should be prefixed by ], like: "C1C2]C3AB" (in this case commands are C1, C2 and C3AB
 <br>This function automatically saves the settings to flash. Saving setting is slower, so should be in ideal
 case executed only once and the program to remember it. The scanner's power usually gets cut when Linea goes to sleep - 
 5 seconds of idle time, so any non-stored to flash settings are lost, but if barcodeEnginePowerControl:TRUE is used on
 2D engine, then even non-saved to flash settings will persist until device disconnects (iOS goes to sleep, physical disconnect)
 @param data command string
 @return TRUE if operation was successful
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)barcodeOpticonSetParams:(NSString *)data;
/**@}*/



/*******************************************************************************
 * MIFARE READER COMMANDS
 *******************************************************************************/
/** @defgroup G_LNMFREADER Mifare Reader Functions
 Functions to work with the Linea's built-in mifare cards reader
 @ingroup G_LINEA
 @{
 */
/**
 Returns mifare engine identification. This is a way to query the engine and see it is there.
 @return identification string
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(NSString *)mfIdent;

/**
 Initializes and powers on the mifare reader module. Call this function before any other mifare functions.
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfInit;

/**
 Powers down mifare reader module. Call this function after you are done with the mifare reader.
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfClose;

/**
 Scans for mifare cards in the area
 @param allCards - true if you want all cards to be requested, or false for only not halted cards
 @param rq1 (optional) upon success, the request status RQ1 will be returned here
 @param rq2 (optional) upon success, the request status RQ2 will be returned here
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfRequestCards:(BOOL)allCards rq1:(uint8_t *)rq1 rq2:(uint8_t *)rq2;

/**
 Returns scanned card serial number
 @param serial upon success, card serial number will be returned here
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfAnticollision:(uint32_t *)serial;

/**
 Select the card to use
 @param serial card serial number, received from {@link #mfAnticollision:(uint32_t *)serial}
 @param sack (optional) SACK parameter is returned upon success
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfSelectCard:(uint32_t)serial sack:(uint8_t *)sack;

/**
 Authenticate card block with direct key data
 @param type key type, either 'A' or 'B'
 @param block block number
 @param key 6 bytes key
 @return mifare command status, one of the MF_STAT_* values
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfAuthByKey:(char)type block:(int)block key:(uint8_t[6])key;

/**
 Reads a 16 byte block of data
 @param address the address of the block to read
 @param data data buffer, where returned block will be written
 @return mifare command status, one of the MF_STAT_* values
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfRead:(int)address data:(uint8_t[16])data;

/**
 Writes a 16 byte block of data
 @param address the address of where to write
 @param data data to write in the block
 @return mifare command status, one of the MF_STAT_* values
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfWrite:(int)address data:(uint8_t[16])data;

/**
 Performs increment/decrement/restore operations
 @param operation operation type, one if the {@link #MF_OPERATION_INCREMENT}, {@link #MF_OPERATION_DECREMENT} or {@link #MF_OPERATION_RESTORE}
 @param src_block source block number
 @param dst_block destination block number
 @param value value to be incremented/decremented with
 @return mifare command status, one of the MF_STAT_* values
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfValueOperation:(int)operation src_block:(int)src_block dst_block:(int)dst_block value:(uint32_t)value;

/**
 Returns mifare reader serial number
 @return mifare command status, one of the MF_STAT_* values
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfGetReaderSerial:(uint32_t *)serial;

/**
 Writes a 4 byte value in the card
 @param address address to write to
 @param value the data
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfWriteValue:(int)address value:(uint32_t)value;

/**
 Stores key securely inside the mifare reader. The key can later be used to authenticate blocks
 @param keyID the index of the key (0-31)
 @param key key data
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfLoadKey:(int)keyID key:(uint8_t[6])key;

/**
 Authenticate block by using previously stored key
 @param type key type, either 'A' or 'B'
 @param keyID the index of the key (0-31)
 @param block block to authenticate
 @param keyID the index of the key (0-31)
 @return mifare command status, one of the MF_STAT_* values
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(int)mfAuthByLoadedKey:(char)type block:(int)block keyID:(int)keyID;
/**@}*/




/** @defgroup G_LNCRYPTO Cryptographic & Security Functions
 Starting from firmware 2.13, Linea provides strong cryptographic support for magnetic card data. The encryption is supported
 on all Linea devices, from software point of view they are all the same, but provide different levels of hardware/firmware security.
 
 <br>An overview of the security, provided by Linea (see each of the crypto functions for further detail):
 
 <br>Hardware/Firmware: 
 
 <br>For magnetic card encryption Linea is using AES256, which is the current industry standard encryption algorithm. The encryption key
 resides in volatile, battery powered ram inside Linea's cpu (for Linea 1.5 onward) and is being lost if anyone tries to break in the
 Linea device in order to prevent the key from being stolen. Magnetic card data, along with device serial number and some random bytes
 (to ensure every packet will be different) are being sent to the iOS program in an encrypted way. 
 
 
 <br>Software: 

 <br>Currently there are 2 types of keys, that can be loaded into Linea: 
 - AUTHENTICATION KEY - used for device authentication (for example the program can lock itself to work with very specific Linea device)
 and encryption of the firmware 
 - ENCRYPTION KEY - used for magnetic card data encryption. To use msr encryption, you don't need to set the AUTHENTICATION KEY. 
 
 <br>Keys: The keys can be set/changed in two ways: 

 <br>1. Using plain key data - this method is easy to use, but less secure, as it relies on program running on iPod/iPhone to have the key
 inside, an attacker could compromise the system and extract the key from device's memory. Call cryptoSetKey to set the keys this way.
 If there is an existing key of the same type inside Linea, you have to pass it too. 
 
 <br>2. Using encrypted key data - this method is harder to implement, but provides better security - the key data, encrypted with old key
 data is sent from a server in secure environment to the program, running on the iOS, then the program forwards it to the Linea.
 The program itself have no means to decrypt the data, so an attacker can't possibly extract the key. Refer to cryptoSetKey documentation
 for more detailed description of the loading process.
 
 <br>The initial loading of the keys should always be done in a secure environment. 
 
 <br>Magnetic card encryption:

 <br>Once ENCRYPTION KEY is set, all magnetic card data gets encrypted, and is now sent via magneticCardEncryptedData instead. The LineaDemo
 program contains sample code to decrypt the data block and extract the contents - the serial number and track data.
 
 <br>As with keys, card data can be extracted on the iOS device itself (less secure, the application needs to have the key inside) or be sent
 to a secure server to be processed. Note, that the encrypted data contains Linea's serial number too, this can be used for Data Origin
 Verification, to be sure someone is not trying to mimic data, coming from another device. 
 
 
 <br>Demo program: the sample program now have "Encryption" tab, where key management can be tested: 
 
 - New AES 256 key - type in the key you want to set (or change to) 
 - Old AES 256 key - type in the previous key, or leave blank if you set the key for the first time 
 
 <br>[SET AUTHENTICATION KEY] and [SET ENCRYPTION KEY] buttons allow you to use the key info in the text fields above to set the key. 
 
 - Decryption key - type in the key, which the demo program will use to try to decrypt card data. This field should contain the
 ENCRYPTION KEY, or something random, if you want to test failed card data decryption.
 @ingroup G_LINEA
 @{
 */

/**
 Generates 16 byte block of random numbers, required for some of the other crypto functions.
 @return 16 bytes of random numbers
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(NSData *)cryptoRawGenerateRandomData;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys
 to reside on the device, but all the operations can be execuded with data, sent from a secure server. See
 cryptoSetKey if you plan to use the key in the mobile device.
 
 <br>Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateLinea
 or cryptoAuthenticateLinea. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or
 magneticCardEncryptedRawData

 <br>Generally the key loading process, using "Raw" commands, a program on the iOS device and a server which holds the keys
 will look similar to:
 
 - (iOS program) calls cryptoRawGenerateRandomData to get 16 bytes block of random data and send these to the server 
 - (Server) creates byte array of 48 bytes consisting of: [RANDOM DATA: 16 bytes][KEY DATA: 32 bytes] 
 - (Server) if there is current encryption key set on the Linea (if you want to change existing key) the server encrypts
 the 48 bytes block with the OLD key 
 - (Server) sends the result data back to the program 
 - (iOS program) calls cryptoRawSetKey with KEY_ENCRYPTION and the data it received from the server
 - (Linea) tries to decrypt the key data if there was already key present, then extracts the key, verifies the random data
 and if everything is okay, sets the key 
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param encryptedData - 48 bytes that consists of 16 bytes random numbers received via call to cryptoRawGenerateRandomData
 and 32 byte AES256 key. If there has been previous key of the same type, then all 48 bytes should be encrypted with it.
 @param keyVersion - the version of the key. On firmware versions less than 2.43 this parameter is ignored and key version
 is considered to be 0x00000000. Key version is useful for the program to determine what key is inside the head.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)cryptoRawSetKey:(int)keyID encryptedData:(NSData *)encryptedData keyVersion:(uint32_t)keyVersion;

/**
 @deprecated
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys
 to reside on the device, but all the operations can be execuded with data, sent from a secure server. See
 cryptoSetKey if you plan to use the key in the mobile device.
 
 <br>Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateLinea
 or cryptoAuthenticateLinea. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or
 magneticCardEncryptedRawData
 
 <br>Generally the key loading process, using "Raw" commands, a program on the iOS device and a server which holds the keys
 will look similar to:
 
 - (iOS program) calls cryptoRawGenerateRandomData to get 16 bytes block of random data and send these to the server 
 - (Server) creates byte array of 48 bytes consisting of: [RANDOM DATA: 16 bytes][KEY DATA: 32 bytes] 
 - (Server) if there is current encryption key set on the Linea (if you want to change existing key) the server encrypts
 the 48 bytes block with the OLD key 
 - (Server) sends the result data back to the program 
 - (iOS program) calls cryptoRawSetKey with KEY_ENCRYPTION and the data it received from the server
 - (Linea) tries to decrypt the key data if there was already key present, then extracts the key, verifies the random data
 and if everything is okay, sets the key 
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param encryptedData - 48 bytes that consists of 16 bytes random numbers received via call to cryptoRawGenerateRandomData
 and 32 byte AES256 key. If there has been previous key of the same type, then all 48 bytes should be encrypted with it.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)cryptoRawSetKey:(int)keyID encryptedData:(NSData *)encryptedData;

/**
 Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateLinea
 or cryptoAuthenticateLinea. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or
 magneticCardEncryptedRawData
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param key 32 bytes AES256 key to set
 @param oldKey 32 bytes AES256 key that was previously used, or null if there was no previous key. The old key
 should match the new key, i.e. if you are setting KEY_ENCRYPTION, then you should pass the old KEY_ENCRYPTION.
 @param keyVersion - the version of the key. On firmware versions less than 2.43 this parameter is ignored and key version
 is considered to be 0x00000000. Key version is useful for the program to determine what key is inside the head.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)cryptoSetKey:(int)keyID key:(NSData *)key oldKey:(NSData *)oldKey keyVersion:(uint32_t)keyVersion;;

/**
 @deprecated
 Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateLinea
 or cryptoAuthenticateLinea. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or
 magneticCardEncryptedRawData
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param key 32 bytes AES256 key to set
 @param oldKey 32 bytes AES256 key that was previously used, or null if there was no previous key. The old key
 should match the new key, i.e. if you are setting KEY_ENCRYPTION, then you should pass the old KEY_ENCRYPTION.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)cryptoSetKey:(int)keyID key:(NSData *)key oldKey:(NSData *)oldKey;

/**
 Returns key version. Valid key ID:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateLinea
 or cryptoAuthenticateLinea. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or
 magneticCardEncryptedRawData
 @return key version or 0xFFFFFFFF if the key version cannot be read (key versions are available in firmware 2.43 or later)
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(uint32_t)cryptoGetKeyVersion:(int)keyID;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys
 to reside on the device, but all the operations can be execuded with data, sent from a secure server. See
 cryptoAuthenticateLinea if you plan to use the key in the mobile device.
 
 <br>Encrypts a 16 bytes block of random data with the stored authentication key and returns the result.

 <br>The idea: if a program wants to work with specific Linea device, it sets AES256 authentication key once, then
 on every connect the program generates random 16 byte block of data, encrypts it internally with the said key,
 then encrypts it with linea too and compares the result. If that Linea contains no key, or
 the key is different, the resulting data will totally differ from the one generated.
 This does not block Linea from operation, what action will be taken if devices mismatch depends on the program.
 @param randomData 16 bytes block of data (presumably random bytes)
 @return Random data, encrypted with the Linea authentication key
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(NSData *)cryptoRawAuthenticateLinea:(NSData *)randomData;

/**
 @note Check out the cryptoRawAuthenticateLinea function, if you want to not use the key inside the mobile device.
 
 <br>Generates random data, uses the key to encrypt it, then encrypts the same data with the stored authentication key
 inside Linea and returns true if both data matches.
 Encrypts a 16 bytes block of random data with the stored authentication key and returns the result.

 <br>The idea: if a program wants to work with specific Linea device, it sets AES256 authentication key once, then
 on every connect the program uses cryptoAuthenticateLinea with that key. If Linea contains no key, or
 the key is different, the function will return FALSE.
 This does not block Linea from operation, what action will be taken if devices mismatch depends on the program.
 @param key 32 bytes AES256 key
 @return TRUE if Linea contains the same authentication key
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)cryptoAuthenticateLinea:(NSData *)key;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys
 to reside on the device, but all the operations can be execuded with data, sent from a secure server. See
 cryptoAuthenticateiPod if you plan to use the key in the mobile device.
 
 <br>Tries to decrypt random data, generated from cryptoRawGenerateRandomData with the stored internal authentication
 key and returns the result. This function is used so that Linea knows a "real" device is currently connected, before
 allowing some functionality. Currently firmware update is protected by this function, once authentication key is set,
 you have to use it or cryptoAuthenticateiPod before you attempt firmware update, or it will error out.

 <br>The idea (considering the iOS device does not have the keys inside, but depends on server):
 - (iOS program) generates random data using cryptoRawGenerateRandomData and sends to the server
 - (Server) encrypts the random data with the same AES256 key that is in the Linea and sends back to the iOS program
 - (iOS program) uses cryptoRawAuthenticateiPod to authenticate with the data, an exception will be generated if authentication fails.
 @param encryptedRandomData 16 bytes block of encrypted data
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(void)cryptoRawAuthenticateiPod:(NSData *)encryptedRandomData;

/**
 @note Check out the cryptoRawAuthenticateiPod function, if you want to not use the key inside the mobile device.
 
 Generates random data, uses the key to encrypt it, then sends to Linea to verify against it's internal authentication
 key. If both keys match, return value is TRUE. This function is used so that Linea knows a "real" device is currently connected, before
 allowing some functionality. Currently firmware update is protected by this function, once authentication key is set,
 you have to use it or cryptoRawAuthenticateiPod before you attempt firmware update, or it will error out.
 @param key 32 bytes AES256 key
 @return TRUE if Linea contains the same authentication key
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters are wrong
 */
-(BOOL)cryptoAuthenticateiPod:(NSData *)key;
/**@}*/



/*******************************************************************************
 * BLUETOOTH COMMANDS
 *******************************************************************************/
/** @defgroup G_LNBLUETOOTH Bluetooth Functions
 Functions to work with Linea's built-in bluetooth module
 @ingroup G_LINEA
 @{
 */
/**
 Returns bluethooth module status.
 @note When bluetooth module is enabled, access to the barcode engine is not possible!
 @return TRUE if bluetooth module is enabled, FALSE otherwise
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(BOOL)btmGetEnabled;

/**
 Enables or disables bluetooth module. Disabling the bluetooth module is currently the way to break existing bluetooth connection.
 @note When bluetooth module is enabled, access to the barcode engine is not possible!
 @param enabled TRUE to enable the engine, FALSE to disable it
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(void)btmSetEnabled:(BOOL)enabled;

/**
 @deprecated Please use bluethooth streams instead
 Sends data to the connected remote device.
 @param data data bytes to write
 @param length the length of the data in the buffer
 @return TRUE if data was written, FALSE if failure
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(BOOL)btmWrite:(void *)data length:(int)length;
-(BOOL)OEMWrite:(void *)data length:(int)length;

/**
 @deprecated Please use bluethooth streams instead
 Sends data to the connected remote device.
 @param data data string to write
 @return TRUE if data was written, FALSE if failure
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(BOOL)btmWrite:(NSString *)data;
-(BOOL)OEMWrite:(NSString *)data;

/**
 @deprecated Please use bluethooth streams instead
 Tries to read data from the connected remote device for specified timeout.
 @param data data buffer, where the result will be stored
 @param length maximum amount of bytes to wait for
 @param timeout maximim timeout in seconds to wait for data
 @return the actual number of bytes stored in the data buffer
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(int)btmRead:(void *)data length:(int)length timeout:(double)timeout;
-(int)OEMRead:(void *)data length:(int)length timeout:(double)timeout;

/**
 @deprecated Please use bluethooth streams instead
 Tries to read string data, ending with CR/LF up to specifed timeout
 @param timeout maximim timeout in seconds to wait for data
 @return the string received or nil
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(NSString *)btmReadLine:(double)timeout;

/**
 Retrieves local bluetooth name, this is the name that Linea will report to bluetooth discovery requests.
 @note this function cannot be called once connection to remote device was established
 @return bluetooth name
 @throw NSPortTimeoutException if there is no connection to Linea
 */
-(NSString *)btmGetLocalName;

/**
 Performs discovery of the nearby bluetooth devices.
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param codTypes bluetooth Class Of Device to look for or 0 to search for all bluetooth devices
 @return array of strings of bluetooth addresses
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(NSArray *)btDiscoverDevices:(int)maxDevices maxTime:(double)maxTime codTypes:(int)codTypes;

/**
 Performs background discovery of the nearby bluetooth devices. The discovery status and devices found will be sent via delegate notifications
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param codTypes bluetooth Class Of Device to look for or 0 to search for all bluetooth devices
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(void)btDiscoverDevicesInBackground:(int)maxDevices maxTime:(double)maxTime codTypes:(int)codTypes;

/**
 Queries device name given the address
 @note this function cannot be called once connection to remote device was established
 @param address bluetooth address returned from btDiscoverDevices/prnDiscoverPrinters
 @return bluetooth device name or nil if query failed
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(NSString *)btGetDeviceName:(NSString *)address;

/**
 Tries to connect to remote device
 @note this function cannot be called once connection to remote device was established
 @param address bluetooth address returned from btDiscoverDevices/prnDiscoverPrinters
 @param pin PIN code if needed, or nil to try unencrypted connection
 @return TRUE if connection was successful, FALSE otherwise
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(BOOL)btConnect:(NSString *)address pin:(NSString *)pin;

/**
 Performs discovery of supported printers. These include PP-60, DPP-250, DPP-350, SM-112.
 @note this function cannot be called once connection to remote device was established
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @return array of strings containing bluetooth device address and bluetooth device name, i.e. if 2 printers are found, the list will contain @"address 1",@"name 1",@"address 2",@"name 2"
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(NSArray *)prnDiscoverPrinters:(double)maxTime;

/**
 Performs discovery of supported printers. These include PP-60, DPP-250, DPP-350, SM-112.
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @return array of strings containing bluetooth device address and bluetooth device name, i.e. if 2 printers are found, the list will contain @"address 1",@"name 1",@"address 2",@"name 2"
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
 -(NSArray *)prnDiscoverPrinters:(int)maxDevices maxTime:(double)maxTime;

/**
 Performs background discovery of supported printers. These include PP-60, DPP-250, DPP-350, SM-112. The discovery status and devices found will be sent via delegate notifications
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw NSInvalidArgumentException if some of the input parameters is wrong
 */
-(void)prnDiscoverPrintersInBackground:(int)maxDevices maxTime:(double)maxTime;

/**
 Bluetooth input stream, you can use it after connecting with btConnect. See NSInputStream documentation.
 **/
@property(readonly) NSInputStream *btInputStream;

/**
 Bluetooth output stream, you can use it after connecting with btConnect. See NSOutputStream documentation.
 **/
@property(readonly) NSOutputStream *btOutputStream;
/**@}*/


/*******************************************************************************
 * ENCRYPTED MAGNETIC HEAD COMMANDS
 *******************************************************************************/
/** @defgroup G_LEMSR Encrypted Magnetic Head Functions
 Functions to work with Linea's optional encrypted magnetic head
 @ingroup G_LINEA
 @{
 */
/**
 Returns information about the specified head firmware data. Based on it, and the current head's name and firmware version
 you can chose to update or not the head's firmware
 @param data - firmware data
 @return dictionary containing extracted data or nil if the data is invalid. Keys contained are:
 <table>
 <tr><td>"deviceModel"</td><td>Head's model, for example "EMSR-DEA"</td></tr>
 <tr><td>"firmwareRevision"</td><td>Firmware revision as string, for example 1.07</td></tr>
 <tr><td>"firmwareRevisionNumber"</td><td>Firmware revision as number MAJOR*100+MINOR, i.e. 1.07 will be returned as 107</td></tr>
 </table>
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 **/
-(NSDictionary *)emsrGetFirmwareInformation:(NSData *)data;

/**
 Checks if the head was tampered or not. If the head's tamper protection have activated, the device should be sent to service for checks
 @return true if the head was tampered and not operational
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(BOOL)emsrIsTampered;

/**
 Returns ECC key version, as supplied by emsrLoadECCPublicKey
 @return ECC key version
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(int)emsrGetECCKeyVersion;

/**
 Loads ECC public key into the head. The new key is signed with the private key, corresponding to the public key currently in the head.
 @param keyID unused, pass 1
 @param keyData key data block consisting of:
 <br>- signature length (1 byte), put 64 (0x40) here
 <br>- ECC signature of the key data, starting from the key format and including key version (64 bytes)
 <br>- new key format (1 byte) - put 0x04 here - unencoded point
 <br>- new public key (64 bytes)
 <br>- key version (4 bytes) in big endian
 @return true if the key was successfully set, false means data was not verified correctly and rejected by the head
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(BOOL)emsrLoadECCPublicKey:(int)keyID keyData:(NSData *)keyData;

/**
 Returns head's model
 @return head's model as string
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(NSString *)emsrGetDeviceModel;

/**
 Returns head's firmware version as number MAJOR*100+MINOR, i.e. version 1.05 will be sent as 105
 @return firmware version
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(int)emsrGetFirmwareVersion;

/**
 Return head's unique serial number as byte array
 @return serial number
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(NSData *)emsrGetSerialNumber;

/**
 Performs firmware update on the encrypted head.
 DO NOT INTERRUPT THE COMMUNICATION DURING THE FIRMWARE UPDATE!
 @param data firmware file data
 @throw NSPortTimeoutException if there is no connection to Linea
 @throw LineaModuleInactiveException if there is no connection to the encrypted head
 */
-(void)emsrUpdateFirmware:(NSData *)data;

/**@}*/

/*******************************************************************************
 * EIC/ISO 15693 CARD COMMANDS
 *******************************************************************************/
/** @defgroup G_LEMSR Encrypted Magnetic Head Functions
 Functions to work with Linea's optional encrypted magnetic head
 @ingroup G_LINEA
 @{
 */

/**
 The command completed successfully.
 */
#define ISO15693_ERR_OK 0x00

/**
The command is not supported, i.e. the request code is not recognized.
 */
#define ISO15693_ERR_COMMAND_NOT_SUPPORTED 0x01

/**
The command is not recognized, for example: a format error occurred.
 */
#define ISO15693_ERR_COMMAND_NOT_RECOGNIZED 0x02

/**
The command option is not supported.
 */
#define ISO15693_ERR_COMMAND_OPTION_NOT_SUPPORTED 0x03

/**
Error with no information given or a specific error code is not supported.
 */
#define ISO15693_ERR_UNKNOWN 0x0F

/**
 The specified block is not available (doesn’t exist).
 */
#define ISO15693_ERR_BLOCK_UNAVAILABLE 0x10

/**
The specified block is already locked and thus cannot be locked again.
 */
#define ISO15693_ERR_BLOCK_ALREADY_LOCKED 0x11

/**
The specified block is locked and its content cannot be changed.
 */
#define ISO15693_ERR_BLOCK_LOCKED 0x12

/**
The specified block was not successfully programmed.
 */
#define ISO15693_ERR_WRITE_FAILED 0x13

/**
The specified block was not successfully locked.
 */
#define ISO15693_ERR_LOCK_FAILED 0x14

/**
 Timeout waiting for the card
 */
#define ISO15693_ERR_TIMEOUT 0xFF

-(BOOL)iso15693SetEnabled:(BOOL)enabled error:(NSError **)error;
-(NSArray *)iso15693ScanCards:(NSError **)error;
-(BOOL)iso15693SelectCard:(NSData *)card error:(NSError **)error;
-(BOOL)iso15693HaltCard:(NSData *)card error:(NSError **)error;
-(BOOL)iso15693ResetHalted:(NSError **)error;
-(BOOL)iso15693LockBlock:(uint8_t)block error:(NSError **)error;
-(NSData *)iso15693ReadBlocks:(uint8_t)startBlock nBlocks:(int)nBlocks error:(NSError **)error;
-(int)iso15693WriteBlocks:(uint8_t)startBlock blockSize:(int)blockSize nBlocks:(int)nBlocks data:(NSData *)data error:(NSError **)error;

/**@}*/

/**
 Adds delegate to the class
 **/
@property(assign) id delegate;

/**
 Provides a list of currently registered delegates
 */
@property(readonly) NSMutableArray *delegates;

/**
 Returns current connection state
 **/
@property(readonly) int connstate;
/**
 Returns connected device name
 **/
@property(readonly) NSString *deviceName;
/**
 Returns connected device model
 **/
@property(readonly) NSString *deviceModel;
/**
 Returns connected device firmware version
 **/
@property(readonly) NSString *firmwareRevision;
/**
 Returns connected device hardware version
 **/
@property(readonly) NSString *hardwareRevision;
/**
 Returns connected device serial number
 **/
@property(readonly) NSString *serialNumber;

/**
 SDK version number in format MAJOR*100+MINOR, i.e. version 1.15 will be returned as 115
 */
@property(readonly) int sdkVersion;
@end

/**@}*/
@interface Linea (Error)
-(BOOL)startScan:(NSError **)error;

@end


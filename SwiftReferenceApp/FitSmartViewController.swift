
import UIKit
import miCoachSensors

/**
 *  This view controller demonstrates how to set time on a FIT_SMART device
 */
class FitSmartViewController: UIViewController, ADIGeneralDeviceDelegate {
    
    // output console on device
    @IBOutlet weak var outputTextView: UITextView!
    
    // set from previous view controller - the selected sensor
    internal var sensor : ADIBluetoothDevice! = nil
    
    // set from previous view controller - the selected sensor
    var fitSmart : ADIFitSmartDevice! = nil
    
    // set up the device after load
    override func viewDidLoad() {
        
        // create the FIT_SMART specific interface
        fitSmart = miCoachSensorsUI.fitSmartDeviceWithSerialNumber(sensor.serialNumber) as! ADIFitSmartDevice
        
        // delegate for the bluetooth callbacks
        fitSmart.delegate = self
        
        // initiate connection
        fitSmart.connect()
    }
   
    // callback for bluetooth device
    func deviceDidConnect(device: ADIGeneralDevice!) {
        
        // log connection
        appendToTextView("Device connected!")

        // pair the device (with example user ID), this can only be done with a resetted device.
        fitSmart.pair(111) { [weak self] (success:Bool) -> Void in
            
            if let strongSelf = self {
                strongSelf.appendToTextView("Pair finished with \(success)")

                // call start sync function
                strongSelf.startSync()
                
                // call set time function
                strongSelf.settime()
            }
        }
    }
    
    // function to write to the textview
    func appendToTextView(string:String!) {
        outputTextView.text = outputTextView.text + string + "\n"
    }
    
    // function to call start sync on FIT_SMART device
    func startSync() {
        
        // start syncing, this method has no completion
        self.fitSmart.startSync()
    }
    
    // function to set the time on the device
    func settime() {

        // set the time on the device
        self.fitSmart.setDeviceTime(NSDate()) { [weak self] (success:Bool) -> Void in
            
            if let strongSelf = self {
                
                // log result
                strongSelf.appendToTextView("set time: \(success)")
                
                // call the endsync function
                strongSelf.endSync()
            }
        }
    }
    
    // function to end sync on FIT_SMART device
    func endSync() {
        
        // switch the device to active state
        self.fitSmart.endSync{ [weak self] (success:Bool) -> Void in
            
            // log if the operation was successful
            if let strongSelf = self {
                strongSelf.appendToTextView("Endsync finished with \(success)")
            }
        }
    }
}

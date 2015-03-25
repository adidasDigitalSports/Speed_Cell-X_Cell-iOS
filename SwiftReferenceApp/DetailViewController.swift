
import UIKit
import miCoachSensors

/**
*  This view controller demonstrates how to download a session from SPEED_CELL
*/
class DetailViewController: UIViewController, ADIGeneralDeviceDelegate {
    
    // display text here "Downloading sessions" when download started
    @IBOutlet weak var statusLabel: UILabel!
    
    // hide the button when download started
    @IBOutlet weak var downloadSessionsButton: UIButton!
    
    // set from previous view controller - the selected sensor
    internal var sensor : ADIBluetoothDevice! = nil
    
    // interface for SPEED_CELL
    var speedCell : ADISpeedCellDevice! = nil

    // button handler
    @IBAction func downloadSessionsTouchUpInside(sender: AnyObject) {
        
        // create the SPEED_CELL specific interface
        speedCell = miCoachSensorsUI.speedcellDeviceWithSerialNumber(sensor.serialNumber) as ADISpeedCellDevice
        
        // delegate for bluetooth callbacks
        speedCell.delegate = self
        
        // initiate connection
        speedCell.connect()
    }
    
    // callback for bluetooth device
    func deviceDidConnect(device: ADIGeneralDevice!) {
        
        // hide button, show label
        downloadSessionsButton.hidden = true
        statusLabel.hidden = false
        
        // initiate session download
        speedCell.downloadSessions { [weak self] (sessions : [AnyObject]!, error : NSError!) -> Void in
            
            // display results
            let alertView = UIAlertView(title: "Download", message: "\(sessions.count) sessions downloaded", delegate: nil, cancelButtonTitle: "OK")
            alertView.alertViewStyle = .Default
            alertView.show()
        }
    }

}


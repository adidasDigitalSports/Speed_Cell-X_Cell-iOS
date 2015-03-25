
import UIKit
import miCoachSensors

/**
*  This view controller demonstrates how to list SPEED_CELL devices nearby.
*/
class MasterViewController: UITableViewController, ADIBluetoothDelegate {

    // list of devices already found nearby
    var sensors = [ADIBluetoothDevice]()
    
    // object responsible for bluetooth communication
    let bluetooth = ADIBluetooth()
    
    // object responsible for validate SDK licensing
    let licensing = ADILicenseManager()
    
    // when view loaded, we initiate licensing and sensor discovery
    override func viewDidLoad() {
        
        // call super
        super.viewDidLoad()
        
        // validate license - you need to fill your license info
        licensing.validateLicenseWithClientId("<Your client id here>", clientSecret : "<Your client secret here>") { [weak self] (success : Bool) -> Void in
        
            // display if validation was successful
            let alertView = UIAlertView(title: "Licensing", message: (success ? "Success" : "Failed"), delegate: nil, cancelButtonTitle: "OK")
            alertView.show()

            // start bluetooth discovery if licensed
            if let strongSelf = self {
                
                if (success) {
                    
                    // need to set delegate to handle if device found
                    strongSelf.bluetooth.bluetoothDelegate = self
                    
                    // look for SPEED_CELL only
                    strongSelf.bluetooth.startDiscoveryWithFilter(ADIDiscoveryFilter(deviceType: ADIBluetoothDeviceTypeSpeedCell))
                }
            }
        }
    }
    
    // callback from bluetooth if discovered a device
    func discoveryService(service: ADIBluetooth!, didFoundDevice device: ADIBluetoothDevice!, ofType type: ADIBluetoothDeviceType) {

        // save to list and display on UI
        sensors.append(device)
        self.tableView.reloadData()
    }
    
    // error handling for bluetooth discovery
    func discoveryService(service: ADIBluetooth!, occuredError error: NSError!) {
    }

    // table view delegate : rows = found devices
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return sensors.count
    }

    // table view delegate : setup content
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        // reuse if can
        let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) as UITableViewCell

        // setup name + serial number
        let object = sensors[indexPath.row]
        cell.textLabel!.text = object.deviceLocalName
        cell.detailTextLabel!.text = object.serialNumber
        return cell
    }
    
    // table view delegate : handle tap on cell
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {

        self.performSegueWithIdentifier("showDetail", sender: self);
    }
    
    // pass the sensor to the next view controller
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        // stop bluetooth
        bluetooth.stopDiscovery()
        
        // pass sensor info
        let index = self.tableView.indexPathForSelectedRow()!.row
        let detailViewController = segue.destinationViewController as DetailViewController
        detailViewController.sensor = sensors[index]
    }

}



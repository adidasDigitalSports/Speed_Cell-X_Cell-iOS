#import "ADIFitSmartFeatureExamples.h"

//  This class presents examples for the Fit Smart device features.
@implementation ADIFitSmartFeatureExamples {
    
    NSMutableArray *_examples;
    NSUInteger _examplesCount;
}

#pragma mark - Helpers

//  Run FitSmart feature examples after each other.
- (void)runAllExamples {
    
    _examples = [NSMutableArray new];
    
    [_examples addObject:NSStringFromSelector(@selector(start))];
   
    [_examples addObject:NSStringFromSelector(@selector(getTimeExample))];
    [_examples addObject:NSStringFromSelector(@selector(setTimeExample))];
    [_examples addObject:NSStringFromSelector(@selector(writeUserConfigurationExample))];
    [_examples addObject:NSStringFromSelector(@selector(getDeviceInfoExample))];
    [_examples addObject:NSStringFromSelector(@selector(uploadWorkoutExample))];
    [_examples addObject:NSStringFromSelector(@selector(uploadWorkoutWithUSDatesExample))];
    [_examples addObject:NSStringFromSelector(@selector(downloadAllSessionsExample))];
    [_examples addObject:NSStringFromSelector(@selector(deleteAllSessionsExample))];
    [_examples addObject:NSStringFromSelector(@selector(writeCalibrationFactorExample))];
    [_examples addObject:NSStringFromSelector(@selector(readCalibrationFactorExample))];
    [_examples addObject:NSStringFromSelector(@selector(readBatteryLevelExample))];
    [_examples addObject:NSStringFromSelector(@selector(getDeviceStateExample))];
    [_examples addObject:NSStringFromSelector(@selector(getAvailableSpacePercentForSessionsExample))];
    [_examples addObject:NSStringFromSelector(@selector(getAvailableSpacePercentForActivityTrackerExample))];
    [_examples addObject:NSStringFromSelector(@selector(downloadActivityRecordsExample))];
    [_examples addObject:NSStringFromSelector(@selector(deleteActivityRecordsExample))];
    [_examples addObject:NSStringFromSelector(@selector(getDeviceStateExample))];

    [_examples addObject:NSStringFromSelector(@selector(endsync))];

    [_examples addObject:NSStringFromSelector(@selector(startDualModeAssessmentExample))];
    [_examples addObject:NSStringFromSelector(@selector(heartRateUpdateExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModeReadyExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModeStartWorkoutExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModeSceneSpeedUpExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModePauseWorkoutExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModeResumeWorkoutExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualUpdateInstantMetricsExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualUpdateSummaryMetricsExample))];
    [_examples addObject:NSStringFromSelector(@selector(dualModeStopWorkoutExample))];
    [_examples addObject:NSStringFromSelector(@selector(isInDualModeExample))];
    [_examples addObject:NSStringFromSelector(@selector(endDualModeExample))];
    
    _examplesCount = _examples.count;
    [self continueRunningExamples];
}

//  This method continues running the next example.
- (void)continueRunningExamples {
    
    if (_examples.count > 0) {
        
        NSString *selectorName = _examples.firstObject;
        SEL selector = NSSelectorFromString(selectorName);
        [_examples removeObjectAtIndex:0];
        self.log(@"");
        self.log([NSString stringWithFormat:@"%02lu/%02lu %@", (unsigned long)(_examplesCount - _examples.count), (unsigned long)_examplesCount, selectorName]);
        [self performSelector:selector withObject:nil afterDelay:5.0];
    }
}

//  This method formats and logs the result of an example, then continues to run next example.
- (void)displayResult:(BOOL)success resultString:(NSString *)resultString {
    
    if (resultString.length > 0) {
        
        // message with result
        self.log([NSString stringWithFormat:@"    success: %@ - %@", success ? @"YES" : @"NO", resultString]);
    }
    else {
        
        // message without result
        self.log([NSString stringWithFormat:@"    success: %@", success ? @"YES" : @"NO"]);
    }
    
    // next example
    [self continueRunningExamples];
}

#pragma mark - Examples

//! [FitSmart startSync example]
//  This is an example for sync starting on the FitSmart device.
- (void)start {
    
    [_fitSmart startSync];
    [self continueRunningExamples];
}
//! [FitSmart startSync example]

//! [FitSmart endSync example]
//  This is an example for sync ending on the FitSmart device and ending the tests.
- (void)end {
    
    [_fitSmart endSync:nil];
}

//! [FitSmart endSync example]
//  This is an example for sync ending on the FitSmart device.
- (void)endsync {
    
    [_fitSmart endSync:nil];
    [self continueRunningExamples];
}
//! [FitSmart endSync example]

//  This is an example for getting the time from the FitSmart device.
- (void)getTimeExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart getDeviceTime:^(NSDate *dateTime) {
        
        NSString *dateString = [NSDateFormatter localizedStringFromDate:dateTime dateStyle:NSDateFormatterShortStyle timeStyle:NSDateFormatterShortStyle];
        BOOL success = (dateTime != nil);
        
        [weakSelf displayResult:success resultString:dateString];
    }];
}

//  This is an example for setting the time on the FitSmart device.
- (void)setTimeExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart setDeviceTime:[NSDate date] success:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}

//! [FitSmart write user configuration example]
//  This is an example for writing a user configuration on the FitSmart device.
- (void)writeUserConfigurationExample {
    
    __weak typeof(self) weakSelf = self;
    
    ADIFitSmartUserConfiguration *testConfiguration = [[ADIFitSmartUserConfiguration alloc] init];
    
    testConfiguration.ageInYears = 1;
    testConfiguration.gender = ADIFitSmartGenderPreferenceMale;
    testConfiguration.heightInCentiMeters = 2;
    testConfiguration.weightInKilograms = 3;
    testConfiguration.heartRateZoneBlueTopInBPM = 4;
    testConfiguration.heartRateZoneBlueMinInBPM = 5;
    testConfiguration.heartRateZoneGreenTopInBPM = 6;
    testConfiguration.heartRateZoneYellowTopInBPM = 7;
    testConfiguration.heartRateZoneRedTopInBPM = 8;
    testConfiguration.paceZoneBlueMinInSecondsPerKM = 9;
    testConfiguration.paceZoneBlueTopInSecondsPerKM = 10;
    testConfiguration.paceZoneGreenTopInSecondsPerKM = 11;
    testConfiguration.paceZoneYellowTopInSecondsPerKM = 12;
    testConfiguration.paceZoneRedTopInSecondsPerKM = 13;
    testConfiguration.uniqueUserIdentifier = @14;
    testConfiguration.showDoubleMetricNames = YES;
    testConfiguration.unit = 1;
    testConfiguration.timeFormat = 1;
    testConfiguration.autoSplitMode = 1;
    testConfiguration.splitMode = ADIFitSmartSplitModePreferenceDistance;
    testConfiguration.autoSplitValue = 1;
    testConfiguration.coachingMethod = ADIFitSmartCoachingMethodPreferencePace;
    testConfiguration.enableLockOfWatchView = YES;
    testConfiguration.enableAWorkout = YES;
    testConfiguration.enableActivityTracking = YES;
    testConfiguration.activityTrackerTargetType = ADIFitSmartActivityTargetPreferenceDistance;
    testConfiguration.activityTrackerGoal = 16;
    testConfiguration.activityTrackerResetTime = 17;
    
    NSMutableArray *metricsArray = [NSMutableArray array];
    ADIFitSmartScreen *screen = [ADIFitSmartScreen fitSmartScreenWithMetricOnTop:ADIFitSmartMetricViewTypeEmpty metricOnBottom:ADIFitSmartMetricViewTypeTime];
    [metricsArray addObject:screen];
    screen = [ADIFitSmartScreen fitSmartScreenWithSingleMetric:ADIFitSmartMetricViewTypeHeartRate];
    [metricsArray addObject:screen];
    screen = [ADIFitSmartScreen fitSmartScreenWithMetricOnTop:ADIFitSmartMetricViewTypeCalories metricOnBottom:ADIFitSmartMetricViewTypeDistance];
    [metricsArray addObject:screen];
    screen = [ADIFitSmartScreen fitSmartScreenWithSingleMetric:ADIFitSmartMetricViewTypeAvgSpeed];
    [metricsArray addObject:screen];
    
    testConfiguration.orderOfMetricViews = metricsArray;
    
    [_fitSmart writeUserConfiguration:testConfiguration completion:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart write user configuration example]


//! [FitSmart download sessions example]
//  This is an example for downloading all sessions from the FitSmart device.
- (void)downloadAllSessionsExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart downloadSessions:^(NSArray *sessions, NSError *error) {
        
        BOOL success = (error == nil);
        
        [weakSelf displayResult:success resultString:[NSString stringWithFormat:@"Downloaded %d sessions", (int)sessions.count]];
    }];
}
//! [FitSmart download sessions example]


//! [FitSmart delete all sessions example]
//  This is an example for deleting all sessions from the FitSmart device.
- (void)deleteAllSessionsExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart deleteAllSessions:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart delete all sessions example]


//! [FitSmart write calibration factor example]
//  This is an exampe for writing a new calibration factor on the FitSmart device.
- (void)writeCalibrationFactorExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart writeCalibrationFactor:1.3 completion:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart write calibration factor example]


//! [FitSmart read calibration factor example]
//  This is an exampe for reading the calibration factor from the FitSmart device.
- (void)readCalibrationFactorExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart readCalibrationFactor:^(float calibrationFactor, BOOL success) {
        
        [weakSelf displayResult:success resultString:[NSString stringWithFormat:@"Calibration Factor: %.2f", calibrationFactor]];
    }];
}
//! [FitSmart read calibration factor example]


//! [FitSmart read battery level example]
//  This is an exampe for reading the battery level from the FitSmart device.
- (void)readBatteryLevelExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart readBatteryLevel:^(NSUInteger batteryLevel) {
        [weakSelf displayResult:YES resultString:[NSString stringWithFormat:@"Level: %lu%%", (unsigned long)batteryLevel]];
        
    }];
}
//! [FitSmart read battery level example]


//! [FitSmart get device info example]
//  This is an exampe for getting the device info from the FitSmart device.
- (void)getDeviceInfoExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart getDeviceInfo:^(ADIFitSmartDeviceInfo *deviceInfo) {
        [weakSelf displayResult:YES resultString:[NSString stringWithFormat:@"S.Num: %@, FirmW.:%@", deviceInfo.serialNumber, deviceInfo.firmwareRevision]];
    }];
}
//! [FitSmart get device info example]


//! [FitSmart upload workout example]
//  This is an exampe for uploading a workout to the FitSmart device.
- (void)uploadWorkoutExample {
    
    __weak typeof(self) weakSelf = self;
    
    ADIFitSmartWorkout *workout = [[ADIFitSmartWorkout alloc] init];
    workout.uniqueId = @123456789;
    workout.workoutIndex = 0;
    workout.date = [NSDate date];
    workout.workoutDescription = @"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    NSMutableArray* intervals = [NSMutableArray array];
    
    ADIFitSmartWorkoutInterval* interval = [[ADIFitSmartWorkoutInterval alloc] init];
    interval.zoneColor = ADIFitSmartWorkoutIntervalZoneColor_Blue;
    interval.intervalDurationInSeconds = 20;
    [intervals addObject:interval];
    
    interval = [[ADIFitSmartWorkoutInterval alloc] init];
    interval.zoneColor = ADIFitSmartWorkoutIntervalZoneColor_Yellow;
    interval.intervalDurationInSeconds = 25;
    [intervals addObject:interval];
    
    workout.intervals = intervals;
    
    [_fitSmart uploadWorkout:workout completion:^(BOOL success) {
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart upload workout example]


//! [FitSmart upload workout with US dates example]
//  This is an exampe for uploading a workout with US Dates to the FitSmart device.
- (void)uploadWorkoutWithUSDatesExample {
    
    __weak typeof(self) weakSelf = self;
    
    ADIFitSmartWorkout *workout = [[ADIFitSmartWorkout alloc] init];
    workout.uniqueId = @5678;
    workout.workoutIndex = 1;
    workout.date = [NSDate date];
    workout.workoutDescription = @"TESTWITHUSDATE";
    
    NSMutableArray* intervals = [NSMutableArray array];
    
    ADIFitSmartWorkoutInterval* interval = [[ADIFitSmartWorkoutInterval alloc] init];
    interval.zoneColor = ADIFitSmartWorkoutIntervalZoneColor_Green;
    interval.intervalDurationInSeconds = 15;
    [intervals addObject:interval];
    
    interval = [[ADIFitSmartWorkoutInterval alloc] init];
    interval.zoneColor = 0;
    interval.intervalDurationInSeconds = 27;
    [intervals addObject:interval];
    
    interval = [[ADIFitSmartWorkoutInterval alloc] init];
    interval.zoneColor = ADIFitSmartWorkoutIntervalZoneColor_Red;
    interval.intervalDurationInSeconds = 34;
    [intervals addObject:interval];
    
    workout.intervals = intervals;
    
    [_fitSmart uploadWorkoutWithUSDates:workout completion:^(BOOL success) {
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart upload workout with US dates example]


//! [FitSmart get device state example]
//  This is an exampe for getting the device state from the FitSmart device.
- (void)getDeviceStateExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart getDeviceState:^(ADIFitSmartState state, ADIFitSmartSubState subState) {
        
        [weakSelf displayResult:YES resultString:[NSString stringWithFormat:@"State: %lu, SubState: %lu", (unsigned long)state, (unsigned long)subState]];
    }];
}
//! [FitSmart get device state example]


//! [FitSmart get available space percent for sessions example]
//  This is an exampe for getting the available percent of space for session from the FitSmart device.
- (void)getAvailableSpacePercentForSessionsExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart getAvailableSpacePercentForSessions:^(NSUInteger percent) {
        
        [weakSelf displayResult:YES resultString:[NSString stringWithFormat:@"Percent: %lu%%", (unsigned long)percent]];
    }];
}
//! [FitSmart get available space percent for sessions example]


//! [FitSmart get available space percent for activity tracker example]
//  This is an exampe for getting the available percent of space for activities from the FitSmart device.
- (void)getAvailableSpacePercentForActivityTrackerExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart getAvailableSpacePercentForActivityTracker :^(NSUInteger percent) {
        
        [weakSelf displayResult:YES resultString:[NSString stringWithFormat:@"Percent: %lu%%", (unsigned long)percent]];
    }];
}
//! [FitSmart get available space percent for activity tracker example]


//! [FitSmart user reset device example]
//  This is an exampe to reset the FitSmart device.
- (void)userResetDeviceExample {
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart userResetDevice:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart user reset device example]


//! [FitSmart reboot device with factory reset example]
//  This is an exampe to reboot the FitSmart device witch factory reset.
- (void)rebootDeviceWithFactoryResetExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart rebootDeviceWithFactoryReset:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart reboot device with factory reset example]


//! [FitSmart reboot device without factory reset example]
//  This is an exampe to reboot the FitSmart device witch factory reset
- (void)rebootDeviceWithoutFactoryResetExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart rebootDeviceWithoutFactoryReset:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart reboot device without factory reset example]


//! [FitSmart download activity records example]
//  This is an exampe for downloading activity records from the FitSmart device.
- (void)downloadActivityRecordsExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart downloadActivityRecords:^(ADIFitSmartActivityRecord *record, NSError *error) {
        
        [weakSelf displayResult:error==nil resultString:[NSString stringWithFormat:@"Datapoints count: %lu", (unsigned long)record.dataPoints.count]];
    }];
}
//! [FitSmart download activity records example]


//! [FitSmart delete activity records example]
//  This is an exampe for deleting activity records from the FitSmart device.
- (void)deleteActivityRecordsExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart deleteActivityRecords:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart delete activity records example]


//! [FitSmart update firmware example]
//  This is an exampe for updating the firmware on the FitSmart device.
- (void)updateFirmwareExample {
    
    __weak typeof(self) weakSelf = self;
    
    NSString* firmwareBinaryPath = [[NSBundle mainBundle] pathForResource:@"fw_update_2.0.2.bin" ofType:nil];
    
    NSData *data = [NSData dataWithContentsOfFile:firmwareBinaryPath];
    
    //! [FitSmart set handler for firmware progress change example]
    [_fitSmart setHandlerForFirmwareProgressChange:^(NSInteger progress) {
        if (progress%5 == 0) {
            weakSelf.log([NSString stringWithFormat:@"  firmware update progress: %lu%%", (long)progress]);
        }
    }];
    //! [FitSmart set handler for firmware progress change example]
    
    [_fitSmart updateFirmware:data completion:^(BOOL success) {
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart update firmware example]


//! [HeartRate start heart rate updates with handler example]
//  This is an exampe for setting a handler for heart rate updates from the FitSmart device.
-(void)heartRateUpdateExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart startHeartRateUpdatesWithHandler:^(ADIHeartRate *heartRateData, NSError *error) {
        
        [self onHearthRateUpdate:heartRateData];
        [weakSelf displayResult:error == nil resultString:nil];
    }];
}
//! [HeartRate start heart rate updates with handler example]


#pragma mark Dual mode

//! [FitSmart start dual mode for free workout example]
//  This is an exampe for starting a free workout in dual mode on FitSmart device.
- (void)startDualModeFreeWorkoutExample {
    
    [self setHandlerForDualModeEventNotification];
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart startDualModeForFreeWorkout:^(BOOL success) {
        
        weakSelf.log(@"free WO start - waiting for HR");
    }];
}
//! [FitSmart start dual mode for free workout example]


//! [FitSmart start dual mode for assessment workout example]
//  This is an exampe for starting an assessment workout in dual mode on FitSmart device.
- (void)startDualModeAssessmentExample {
    
    [self setHandlerForDualModeEventNotification];
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart startDualModeForAssessmentWorkout:^(BOOL success) {
        
        weakSelf.log(@"assessment WO start - waiting for HR");
    }];
}
//! [FitSmart start dual mode for assessment workout example]


//! [FitSmart start dual mode for coached workout example]
//  This is an exampe for starting a coached workout in dual mode on FitSmart device.
- (void)startDualModeForCoachedWorkoutExample {
    
    [self setHandlerForDualModeEventNotification];
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart startDualModeForCoachedWorkout:^(BOOL success) {
        
        weakSelf.log(@"coached WO start - waiting for HR");
    }];
}
//! [FitSmart start dual mode for coached workout example]


//! [FitSmart start dual mode for strength and flex workout example]
//  This is an exampe for starting a strength & flex workout in dual mode on FitSmart device.
- (void)startDualModeForStrengthAndFlexWorkoutExample {
    
    [self setHandlerForDualModeEventNotification];
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart startDualModeForStrengthAndFlexWorkout:^(BOOL success) {
        
        weakSelf.log(@"strength & flex WO start - waiting for HR");
    }];
}
//! [FitSmart start dual mode for strength and flex workout example]


//! [FitSmart set handler for dual mode event notification example]
- (void) setHandlerForDualModeEventNotification {
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart setHandlerForDualModeEventNotification:^(ADIFitSmartDualModeEventType eventType) {
        
        [weakSelf onEventNotification:eventType];
    }];
}
//! [FitSmart set handler for dual mode event notification example]


//  This is an event notification handler to handle dual moad events.
//  param: eventType Received event type.
- (void)onEventNotification: (ADIFitSmartDualModeEventType) eventType {
    NSLog(@"event received: %lu", (unsigned long)eventType);
    if (eventType == ADIFitSmartDualModeEventTypeHeartRateFound) {
        [self dualModeHearthRateFound];
    }
}

//  A helper method to display when heart rate was found.
- (void)dualModeHearthRateFound {
    
    [self displayResult:YES resultString:@"Heart Rate found"];
}


//! [FitSmart dual mode ready example]
//  This is an exampe for sending a dual mode ready command to the FitSmart device.
- (void)dualModeReadyExample {
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModeReady:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode ready example]


//! [FitSmart dual mode scene AW zone up example]
//  This is an exampe for sending speed up command to the FitSmart device.
- (void)dualModeSceneSpeedUpExample {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModeSceneAWZoneUp:ADIFitSmartDualModeZoneColorRed];
    
    [weakSelf displayResult:YES resultString:@"Check device for arrow up"];
    
}
//! [FitSmart dual mode scene AW zone up example]


//! [FitSmart dual mode start workout example]
//  This is an exampe for starting a workout in dual mode on FitSmart device.
- (void)dualModeStartWorkoutExample {
    
    [self setHandlerForDualModeSensorReadings];
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModeStartWorkout:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode start workout example]


//! [FitSmart set handler for dual mode sensor readings example]
-(void)setHandlerForDualModeSensorReadings {
    
    __weak typeof(self) weakSelf = self;
    
    [_fitSmart setHandlerForDualModeSensorReadings:^(ADIFitSmartSensorReadings *readings) {
        [weakSelf onDualModeSensorReadingsNotification:readings];
    }];
}
//! [FitSmart set handler for dual mode sensor readings example]


//  This function is called when a setHandlerForDualModeSensorReadings is fired from the FitSmart device.
//  param: readings The received sensor readings.
- (void)onDualModeSensorReadingsNotification:(ADIFitSmartSensorReadings *)readings {
    
    self.log([NSString stringWithFormat:@"        sensorReadings: speed: %@ hr: %@", readings.speed, readings.heartRate]);
    [_fitSmart setHandlerForDualModeSensorReadings:nil];
}


//! [FitSmart dual mode pause workout example]
//  This is an exampe for pausing a workout in dual mode on FitSmart device.
- (void)dualModePauseWorkoutExample {

    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModePauseWorkout:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode pause workout example]


//! [FitSmart dual mode resume workout example]
//  This is an exampe for resuming a workout in dual mode on FitSmart device.
- (void)dualModeResumeWorkoutExample {

    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModeResumeWorkout:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode resume workout example]


//! [FitSmart dual mode update instant metrics example]
//  This is an exampe for updating the instant metrics on the FitSmart device.
- (void)dualUpdateInstantMetricsExample {
    
    __weak typeof(self) weakSelf = self;
    
    ADIFitSmartSensorReadings * sensorReadings = [[ADIFitSmartSensorReadings alloc] init];
    
    sensorReadings.heartRate = @89;
    sensorReadings.workoutTime = @220;
    sensorReadings.distance = @80;
    sensorReadings.calories = @30;
    sensorReadings.pace = @301;
    sensorReadings.avgPace = @330;
    sensorReadings.speed = @47.4;
    sensorReadings.avgSpeed = @27.2;
    sensorReadings.strideRate = @29.44;
    sensorReadings.steps = @221;
    sensorReadings.runScore = @70;
    sensorReadings.timestampUTC = @1437998844;
    
    
    [_fitSmart dualModeUpdateInstantMetrics:sensorReadings completion:^(BOOL success) {
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode update instant metrics example]


//! [FitSmart dual mode update summary metrics example]
//  This is an exampe for updating the summary metrics on the FitSmart device.
- (void)dualUpdateSummaryMetricsExample {

    __weak typeof(self) weakSelf = self;
    
    ADIFitSmartSensorReadings * sensorReadings = [[ADIFitSmartSensorReadings alloc] init];
    
    sensorReadings.heartRate = @111;
    sensorReadings.workoutTime = @320;
    sensorReadings.distance = @180;
    sensorReadings.calories = @130;
    sensorReadings.pace = @201;
    sensorReadings.avgPace = @330;
    sensorReadings.speed = @47.4;
    sensorReadings.avgSpeed = @27.2;
    sensorReadings.strideRate = @29.44;
    sensorReadings.steps = @221;
    sensorReadings.runScore = @170;
    sensorReadings.timestampUTC = @1438888888;
    
    [_fitSmart dualModeUpdateSummaryMetrics:sensorReadings completion:^(BOOL success) {
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode update summary metrics example]


//! [FitSmart dual mode stop workout example]
//  This is an exampe for stopping a workout in dual mode on FitSmart device.
- (void)dualModeStopWorkoutExample {

    __weak typeof(self) weakSelf = self;
    
    [_fitSmart dualModeStopWorkout:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart dual mode stop workout example]


//! [FitSmart is in dual mode example]
//  This is an exampe for checking if the FitSmart device is in dual mode.
- (void)isInDualModeExample {
    
    BOOL isInDualMode = [_fitSmart isInDualMode];
    
    [self displayResult:isInDualMode resultString:nil];
}
//! [FitSmart is in dual mode example]


//! [FitSmart end dual mode example]
//  This is an exampe for ending the dual mode on the FitSmart device.
- (void)endDualModeExample {

    __weak typeof(self) weakSelf = self;
    
    [_fitSmart endDualMode:^(BOOL success) {
        
        [weakSelf displayResult:success resultString:nil];
    }];
}
//! [FitSmart end dual mode example]


//  This is a method called when a heart rate update handler fires from the FitSmart device.
//  param: heartRateData The received heart rate.
- (void)onHearthRateUpdate:(ADIHeartRate *)heartRateData {
    
    self.log([NSString stringWithFormat:@"  HR: %lu", (unsigned long)heartRateData.heartRate]);
    [_fitSmart startHeartRateUpdatesWithHandler:nil];
}

@end

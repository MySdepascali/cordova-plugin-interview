# cordova-plugin-interview

Native plugin for blockchain-based video-interviews.

Uses InterviewSDK v2.8

## Plugin for iOS (minimum version 8.0) and Android (Api 19)

This plugin cannot work on simulator, because it uses some device-specific capablities (camera, microphone etc)

## Installation for iOS

```
npm install https://github.com/aabluedragon/node-xcode.git
cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git
cordova plugin add cordova-plugin-disable-bitcode --save
```

## Installation for Android

```
install Android SDK, JRE, JDK
�e sure that the environment variable is set correctly
For Windows install Node.js and run it
npm install -g ionic@latest
npm install -g cordova
ionic cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git --force
ionic cordova prepare --force
If the project was not made on Windows run 'npm rebuild node-sass --force'
ionic cordova build android --force
```


## Usage



You can simply request demo-interview without any parameters. Specify only callback routines for result processing.

```
// Demo mode
interview.showDemoInterview(onSuccess, onError);

// Success callback routine (returns dictionary with interview result)
function onSuccess(taskDictionary) {
	alert('Interview has just been completed');
}

//Error callback (returns string with error description)
function onFail(error) {
	alert('Failed because: ' + message);
}
```

If you want to set a custom API backend, use the following method. In addition to the URL you must specify username with password to login and demo taskId. Interviews from all demo tasks will be uploaded for this taskId.

```
// Setting API backend to the SDK
interview.setEngine(onSuccess, onError, 'https://engine_server.com/', 'username', 'password', 'demo_taskId');
```

To show an interview with the specified identifier and the quality of the output video, you can use the following method. The video quality parameter is a string that can assume the following values (case-insensitive):

 - `'InterviewVideoQualityLow'` or `'low'` - the worst quality with a minimum upload size
 - `'InterviewVideoQualityMedium'` or `'medium'` - the normal quality with a medium upload size
 - `'InterviewVideoQualityHigh'` or `'high'` - the best quality with a large upload size

```
// Show interview with the specified taskId and output video quality
interview.setEngine(onSuccess, onError, 'taskId', 'medium');
```

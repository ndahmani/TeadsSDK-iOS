project 'TeadsSampleApp.xcodeproj'

# Uncomment the next line to define a global platform for your project
# platform :ios, '10.0'

target 'TeadsSampleApp' do
  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks
  use_frameworks!

  # Pods for TeadsSampleApp
  pod 'GoogleMobileAdsMediationTeads', '4.8.0'
  pod 'MoPub-Teads-Adapters', '4.8.0'
  pod 'TeadsSASAdapter', '4.8.0'
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64 arm64e armv7 armv7s"
      config.build_settings["EXCLUDED_ARCHS[sdk=iphoneos*]"] = "i386 x86_64"
    end
  end
end

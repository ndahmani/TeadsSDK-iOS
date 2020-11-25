project 'TeadsSampleApp.xcodeproj'

# Uncomment the next line to define a global platform for your project
# platform :ios, '10.0'
def inApp_pods(dependencyName, localPath, sdkRepository, dependencyBranchName = nil)
    branchRef = ENV["BITRISEIO_GIT_BRANCH_DEST"] || 'develop'
    puts "branchRef is '#{branchRef}'"
    $branchName = branchRef
    if ENV["BITRISE_GIT_BRANCH"].nil?
        $branchName = `git rev-parse --abbrev-ref HEAD`.strip
    else
        $branchName = ENV["BITRISE_GIT_BRANCH"]
    end

    puts "local branch name is '#{$branchName}'"
    if not localPath.nil?
        puts "localPath exists: '#{localPath}'"
        pod dependencyName, :path => localPath
    else
        if not dependencyBranchName.nil?
            puts "dependency branch name argument is specified '#{dependencyBranchName}'"
            $branchName = ENV['SDK_GIT_BRANCH']
        elsif not $branchName.eql? branchRef
            puts "local branch '#{$branchName}' does not equals branchRef '#{branchRef}'"
            $branchExists = lastRemoteCommit(sdkRepository, $branchName)
            if $branchExists.nil?
                puts "remote branch '#{$branchName}' does not exists '#{$branchExists}' on repository '#{sdkRepository}'"
                $branchName = branchRef
            end
        end
        pod dependencyName, :git => sdkRepository, :branch => $branchName
    end
end

def lastRemoteCommit(repository, branch)
    lastCommit = `git ls-remote #{repository} refs/heads/#{branch} | cut -f 1`
    return nil unless lastCommit
    lastCommit = lastCommit.strip.split.last
    return nil unless lastCommit
    return nil if !lastCommit.match(/[0-9a-f]{40}/) #prevent CI to display "Warning: Permanently added ..."
    return lastCommit
end

def sdk_pods
    inApp_pods('TeadsSDK', ENV['TEADS_SDK_DEV_PODS_PATH'], 'git@github.com:ebuzzing/service-inapp-sdk-ios.git', ENV['SDK_GIT_BRANCH'])
end

target 'TeadsSampleApp' do
  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks
  use_frameworks!

  # Pods for TeadsSampleApp

  sdk_pods
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

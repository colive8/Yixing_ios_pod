Pod::Spec.new do |s|
  s.name             = 'yixingAd'
  s.version          = '1.7.1'
  s.summary          = 'Yixing Ad SDK'
  s.description      = 'Yixing Ad SDK Objective-C (binary distribution). Lightweight headers and external dependencies.'
  s.homepage         = 'https://github.com/colive8/Yixing_ios_pod'
  s.license          = { :type => 'MIT' }
  s.author           = { 'yixing' => 'dev@example.com' }

  # 远程二进制分发（Git + tag），与仓库标签一致
  s.source           = { :git => 'https://github.com/colive8/Yixing_ios_pod.git', :tag => s.version }

  s.platform     = :ios, '12.0'
  s.requires_arc = true
  
  # 标记为静态框架（本身是静态库，但有外部依赖）
  s.static_framework = true
  s.vendored_frameworks = 'yixingAd.xcframework'

  # Swift 导入模块名保持一致
  s.module_name = 'yixingAd'

  # 恢复标准依赖声明
  # 用户集成时 CocoaPods 会自动处理这些依赖的下载和链接
  s.dependency 'gRPC-ProtoRPC'
  s.dependency 'Protobuf'

  # 显式链接系统框架和库
  s.frameworks = 'CoreGraphics', 'SystemConfiguration', 'CFNetwork', 'Security', 'CoreTelephony'
  s.libraries  = 'c++', 'z'

  # 编译设置
  s.pod_target_xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++17',
    'CLANG_CXX_LIBRARY' => 'libc++',
    'ENABLE_BITCODE' => 'NO',
    'DEFINES_MODULE' => 'YES',
    'OTHER_LDFLAGS' => '$(inherited) -ObjC',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) YIXINGAD_SDK_VERSION_CODE=1701'
  }
end

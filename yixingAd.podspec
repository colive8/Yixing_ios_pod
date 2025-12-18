Pod::Spec.new do |s|
  s.name             = 'yixingAd'
  s.version          = '1.6.4'
  s.summary          = 'Yixing Ad SDK'
  s.description      = 'Yixing Ad SDK Objective-C (binary distribution)'
  s.homepage         = 'https://github.com/colive8/Yixing_ios_pod'
  s.license          = { :type => 'MIT' }
  s.author           = { 'yixing' => 'dev@example.com' }

  # 远程二进制分发（Git + tag），与仓库标签一致
  s.source           = { :git => 'https://github.com/colive8/Yixing_ios_pod.git', :tag => s.version }

  s.platform     = :ios, '12.0'
  s.requires_arc = true
  # 二进制框架由其自身的类型决定（动态/静态），不在此处强制

  # 使用 XCFramework 二进制分发（更新至 1.6.1）
  s.vendored_frameworks = 'yixingAd.xcframework'

  # Swift 导入模块名保持一致
  s.module_name = 'yixingAd'

  # 依赖版本锁定，避免歧义（移除 AFNetworking）
  s.dependency 'gRPC', '1.75.0'
  s.dependency 'gRPC-ProtoRPC', '1.75.0'
  s.dependency 'Protobuf', '4.33.0'

  # 显式链接系统框架，避免 CoreGraphics 符号缺失
  s.frameworks = 'CoreGraphics'

  # 编译设置：启用模块并统一 C++ 标准
  s.pod_target_xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++17',
    'CLANG_CXX_LIBRARY' => 'libc++',
    'ENABLE_BITCODE' => 'NO',
    'DEFINES_MODULE' => 'YES',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1 YIXINGAD_SDK_VERSION_CODE=1601'
  }
end

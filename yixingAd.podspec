Pod::Spec.new do |s|
  s.name             = 'yixingAd'
  s.version          = '1.6.7'
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

  # 使用静态库 XCFramework 分发（真正静态，已内联 gRPC 依赖）
  s.static_framework = true
  s.vendored_libraries = 'yixingAd.xcframework'

  # Swift 导入模块名保持一致
  s.module_name = 'yixingAd'

  # 已静态内联 gRPC/Protobuf 代码，无需在宿主侧再声明这些依赖

  # 显式链接系统框架，避免 CoreGraphics 符号缺失
  s.frameworks = 'CoreGraphics', 'SystemConfiguration', 'CFNetwork', 'Security'

  # 编译设置（宿主方无须开启 Swift 模块接口等设置）
  s.pod_target_xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++17',
    'CLANG_CXX_LIBRARY' => 'libc++',
    'ENABLE_BITCODE' => 'NO',
    'DEFINES_MODULE' => 'YES',
    'OTHER_LDFLAGS' => '$(inherited) -ObjC',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) YIXINGAD_SDK_VERSION_CODE=1607'
  }
end

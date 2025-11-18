Pod::Spec.new do |s|
  s.name             = 'yixingAd'
  s.version          = '1.0.1'
  s.summary          = 'Yixing Ad SDK'
  s.description      = 'Yixing Ad SDK Objective-C'
  s.homepage         = 'https://example.com/yixingAd'
  s.license          = { :type => 'MIT' }
  s.author           = { 'yixing' => 'dev@example.com' }
  # 发布到第三方使用时，请将 :git 替换为你的仓库地址并打 tag
  s.source           = { :git => 'https://example.com/your-org/yixingAd.git', :tag => s.version }

  s.platform     = :ios, '12.0'
  s.requires_arc = true
  s.static_framework = true

  # 改用源码分发并导出公共头文件，兼容 #import <yixingAd/yixingAd.h>
  s.source_files = 'yixingAd/**/*.{h,m}'
  s.public_header_files = 'yixingAd/**/*.h'
  # s.vendored_frameworks = 'yixingAd.xcframework'
  # s.header_mappings_dir = nil
  # s.header_dir = nil
  s.module_name = 'yixingAd'
  # 打包资源到独立的bundle中，避免命名冲突
  s.resource_bundles = {
    'yixingAd' => ['yixingAd/Resources/**/*']
  }

  # 统一依赖版本（锁定确切版本以消除歧义）
  s.dependency 'AFNetworking'
  s.dependency 'gRPC', '1.75.0'
  s.dependency 'gRPC-ProtoRPC', '1.75.0'
  s.dependency 'Protobuf', '4.33.0'

  # 保持现有编译设置
  s.pod_target_xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++17',
    'CLANG_CXX_LIBRARY' => 'libc++',
    'ENABLE_BITCODE' => 'NO',
    'DEFINES_MODULE' => 'YES',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1 YIXINGAD_SDK_VERSION_CODE=1'
  }
end

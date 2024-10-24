project('calculator', 'cpp', 'c',
  version: '1.0',
  default_options: ['cpp_std=c++20', 'buildtype=debugoptimized', 'optimization=2']
)

sources = files('src/main.cpp')

gtkmm = dependency('gtkmm-4.0', required: true)
gtk4 = dependency('gtk4', required: true)

executable('calculator', sources,
  dependencies: [ gtkmm, gtk4],
)

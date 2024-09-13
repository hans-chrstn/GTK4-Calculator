project('calculator', 'cpp', 'c',
  version: '0.0.0',
  default_options: [
    'cpp_std=c++17'
  ]
)

gtkmm_dep = dependency('gtkmm-4.0')

program_name = 'calculator'

cpp_sources = [
  'src/main.cc',
]

cpp_flags = [
  '-O2',
]

executable(program_name,
  cpp_sources,
  dependencies : gtkmm_dep,
  cpp_args : cpp_flags
)

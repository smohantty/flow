project('flow', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_FLOW']

shlib = shared_library('flow', 'flow.cpp',
  install : true,
  cpp_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('flow', 'flow_test.cpp',
  link_with : shlib)
test('flow', test_exe)

# Make this library usable as a Meson subproject.
flow_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('flow.hpp', subdir : 'flow')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'flow',
  filebase : 'flow',
  description : 'Meson sample project.',
  subdirs : 'flow',
  libraries : shlib,
  version : '0.1',
)

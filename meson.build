project('RootTest', 'cpp', version:'0.0.1')

root_config=find_program('root-config', required:true)

root_incdir=run_command(root_config, '--incdir', check: true).stdout().strip()
root_libs=run_command(root_config, '--libs', check: true).stdout().strip().split(' ')
root_cflags=run_command(root_config, '--cflags', check: true).stdout().strip().split(' ')
root_ldflags=run_command(root_config, '--ldflags', check: true).stdout().strip().split(' ')
root_version=run_command(root_config, '--version', check: true).stdout().strip()
root_dep=declare_dependency(compile_args: root_cflags, link_args: root_ldflags + root_libs, include_directories: root_incdir)

rootcling=find_program('rootcling', required:true)

dict_gen=generator(
	rootcling,
	output:['@BASENAME@Dict.cc', '@BASENAME@Dict_rdict.pcm'],
	arguments: ['-f', '@OUTPUT0@', '-c', '-p',
        '-I'+meson.current_source_dir(),
        '-I'+root_incdir ,
	'@INPUT@', '@EXTRA_ARGS@']
)

dict_files=[]
files=dict_gen.process ('callbacks.h', extra_args: 'callbacksLinkDef.h')
custom_target('callbackspcm', input: files, output: 'callbacksDict_rdict.pcm', command: ['cp', '@INPUT1@', '@OUTPUT@'], install: true, install_dir: get_option('libdir'))
dict_files+=files

library_include_dir = get_option ('includedir') / 'root-test'
install_headers('callbacks.h', install_dir: library_include_dir)

test_lib=library('testlib', dict_files + 'callbacks.cc', dependencies: root_dep, install: true)
test_app=executable(
  'testapp', 'test.cc',
  dependencies: root_dep,
  link_with: test_lib,
  install: true,
  cpp_args: ['-DCALLBACKS_H="'+ get_option('prefix') / library_include_dir / 'callbacks.h'+'"']
)


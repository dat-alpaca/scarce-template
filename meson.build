project('scarce-template', 
    'c',
    default_options: [
        'scarce:build_loader=true',
        'scarce:build_testbed=false',
        'scarce:use_native_windowing=true'
    ]
)

# Scarce dependencies:
scarce = subproject('scarce')

application_dep = scarce.get_variable('application_dep')
application_c_args = scarce.get_variable('application_c_args')
application_link_args = scarce.get_variable('application_link_args')
linker_script = scarce.get_variable('linker_script')
engine_internal_includes = scarce.get_variable('engine_internal_includes')
executable_dependencies = scarce.get_variable('executable_dependencies')

sources = [
    'src/main.c'
]

# Game:
game = executable(
    'game',
    sources: sources,
    include_directories: ['src/', engine_internal_includes],

    dependencies: application_dep,
    c_args: application_c_args,
    link_args: application_link_args,
    link_depends: linker_script,
    pie: true,
    gnu_symbol_visibility: 'hidden',

    dependencies: [executable_dependencies],

    install: true,
    install_dir: '.',
    install_tag: 'application'
)


# Post install:
post_install_script = scarce.get_variable('post_install')
meson.add_install_script(
    post_install_script, 
    'game', 
    'main.bin', 
    install_tag: 'application'
)

install_subdir('assets',
    strip_directory: false,
    install_dir: '.',
    install_tag: 'application'
)

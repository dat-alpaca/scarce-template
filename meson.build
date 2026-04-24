project('scarce-template', 
    'c',
    default_options: [
        'scarce:build_loader=true',
        'scarce:build_testbed=false'
    ]
)

# Scarce dependencies:
scarce = subproject('scarce')

application_dep = scarce.get_variable('application_dep')
application_c_args = scarce.get_variable('application_c_args')
application_link_args = scarce.get_variable('application_link_args')
linker_script = scarce.get_variable('linker_script')

# Game:
game = executable(
    'game',
    'src/main.c',
    dependencies: application_dep,
    link_depends: linker_script,
    pie: true,
    gnu_symbol_visibility: 'hidden',

    install: true,
    install_dir: '.',
    install_tag: 'application'
)

# Post install:
post_install_script = scarce.get_variable('post_install')
meson.add_install_script(post_install_script, 'game', 'game.bin', install_tag: 'application')

install_subdir('assets',
    strip_directory: false,
    install_dir: '.',
    install_tag: 'application'
)
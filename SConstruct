import os
import platform

def find_vcpkg_path():
    possible_paths = [
        os.path.expanduser('~/vcpkg'),
        'C:/vcpkg',
        os.path.expanduser('~/.vcpkg'),
    ]
    
    for path in possible_paths:
        if os.path.exists(path):
            return path
    return None

vcpkg_path = find_vcpkg_path()

is_windows = platform.system() == "Windows"
is_mac = platform.system() == "Darwin"
is_linux = platform.system() == "Linux"

is_arm = platform.machine().startswith('arm')
is_arm64 = platform.machine().startswith('aarch64') or platform.machine().startswith('arm64')

env = Environment()

if is_windows:
    env.Append(CXXFLAGS=['/EHsc', '/MD'])
elif is_mac:
    env.Append(CXXFLAGS=['-std=c++17'])
else:
    env.Append(CXXFLAGS=['-std=c++17'])

if vcpkg_path:
    triplet = ''
    if is_windows:
        triplet = 'x64-windows'
    elif is_mac:
        if is_arm:
            triplet = 'arm64-osx'
        else:
            triplet = 'x64-osx'
    else:
        if is_arm:
            if is_arm64:
                triplet = 'arm64-linux'
            else:
                triplet = 'arm-linux'
        else:
            triplet = 'x64-linux'

    vcpkg_installed = os.path.join(vcpkg_path, 'installed', triplet)
    
    env.Append(
        CPPPATH=[
            os.path.join(vcpkg_installed, 'include'),
        ],
        LIBPATH=[
            os.path.join(vcpkg_installed, 'lib'),
        ]
    )

if is_windows:
    env.Append(
        LIBS=['opengl32', 'glew32', 'glfw3dll']
    )
elif is_mac:
    env.Append(LINKFLAGS=['-framework', 'OpenGL', '-framework', 'Cocoa', '-framework', 'IOKit'])
    env.Append(
        LIBS=['GLEW', 'glfw3']
    )
else:
    env.Append(
        LIBS=['GL', 'GLEW', 'glfw']
    )

env.Program('opengl_info', ['main.cpp'])
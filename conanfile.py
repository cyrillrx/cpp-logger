from conans import ConanFile, CMake
import os

class Logger(ConanFile):
    name = "Logger"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    exports = "logger/*"

    # def build(self):
    #     cmake = CMake(self.settings)
    #     self.run('cd logger && cmake . %s' % cmake.command_line)
    #     self.run("cd logger && cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="logger")
        self.copy("*.lib", dst="lib", src="logger/lib")
        self.copy("*.a", dst="lib", src="logger/lib")

    def package_info(self):
        self.cpp_info.libs = ["logger"]

    def test(self):
        # equal to ./bin/greet, but portable win: .\bin\greet
        self.run(os.sep.join([".","bin", "greet"]))
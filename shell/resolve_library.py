import platform

class Raylib:
    
    @staticmethod

    def get_dist() -> str:
    
        system: str = platform.system().lower()
        architecture: str = platform.architecture()[0]
        bits: str = "32" if architecture == "32bit" else "64"

        folder: str
        if system == "linux":
            folder = f"raylib-5.5_linux{'i386' if bits == '32' else '_amd64'}"
            
        elif system == "windows":
            compiler = "mingw-w64"
            folder = f"raylib-5.5_win{bits}_{compiler}"
        
        else:
            raise Exception("Unsupported OS")

        return folder   
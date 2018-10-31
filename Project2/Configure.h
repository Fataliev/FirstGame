#pragma once
class Configure
{
public:
	static Configure *get() {
		static Configure conf;
		return &conf;
	}

	int getWindowWidth() { return windowWidth; }
	int getWindowHeight() { return windowHeight; }

private :
	Configure() { }
	~Configure() { }

	int windowWidth = 800;
	int windowHeight = 600;
	
};


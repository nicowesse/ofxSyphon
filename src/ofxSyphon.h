/*
 *  ofxSyphonServer.h
 *  syphonTest
 *
 *  Created by astellato,vade,bangnoise on 11/6/10.
 *
 *  http://syphon.v002.info/license.php
 */

#include "ofMain.h"

#ifdef TARGET_OSX

#import "ofxSyphonClient.h"
#import "ofxSyphonServer.h"
#import "ofxSyphonServerDirectory.h"

#else

class ofxSyphonNSObject {};
class ofxSyphonServerDescription {};

class ofxSyphonServer {
public:
	ofxSyphonServer() {};
    void setName(const std::string& n) { name = n; };
    std::string getName() { return name; };
	void publishScreen() {};
	void publishTexture(ofTexture* inputTexture) {};
	void publishTexture(GLuint id, GLenum target, GLsizei width, GLsizei height, bool isFlipped) {};
protected:
    std::string name;
};



class ofxSyphonClient {
public:
    ofxSyphonClient() : bSetup(false) {};

    void setup() { bSetup = true; };
    bool isSetup() { return bSetup; };

    void set(ofxSyphonServerDescription _server) {};
    void set(const std::string& _serverName, const std::string& _appName) { appName = _appName; serverName = _serverName; };

    void setApplicationName(const std::string& _appName) { appName = _appName; };
    void setServerName(const std::string& _serverName) { serverName = _serverName; };

    const std::string& getApplicationName() { return appName;  };
    const std::string& getServerName() { return serverName; };

    void bind() {};
    void unbind() {};

    /*
     To use the texture with getTexture()
     you should surround it with bind() and
     unbind() functions */

    ofTexture& getTexture() { return mTex; }

    void draw(float x, float y, float w, float h) {};
    void draw(float x, float y) {};
    void drawSubsection(float x, float y, float w, float h, float sx, float sy, float sw, float sh) {};
    void drawSubsection(float x, float y, float sx, float sy, float sw, float sh) {};


    float getWidth() { return width; };
    float getHeight() { return height; };

protected:
    ofxSyphonNSObject mClient;
    ofxSyphonNSObject latestImage;
    ofTexture mTex;
    int width, height;
    bool bSetup;
    std::string appName, serverName;
};

#endif





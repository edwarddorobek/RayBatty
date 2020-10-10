
#pragma once

namespace Batty {
    class RenderEngine 
    {
        public:
            RengerEngine() {}
            RenderEngine(camera, size, size);

            addObject();
            loadScene();

            drawFrame();
            writeFrame()


        private:
            camera;
            outputspace;
            scene;
    };
}
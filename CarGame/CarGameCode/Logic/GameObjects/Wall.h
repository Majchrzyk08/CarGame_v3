#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Game;

class Wall : public GameObject{
    bool alive = true;
public:
    Wall(Game* g);
    ~Wall();

    void draw();
    void update();

    bool toDelete() { return !alive; }
};
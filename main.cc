int main() {
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
	app.setFramerateLimit(50);

    Texture t1,t2,t3;
    t1.loadFromFile("background.png");
    t2.loadFromFile("car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1), sCar(t2);
    sBackground.scale(2,2);

    sCar.setOrigin(22, 22);
}

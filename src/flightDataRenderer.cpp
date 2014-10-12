#include "cinder/app/AppBasic.h"
#include <list>

#include "cinder/Vector.h"

#include "utility/logging/logging.h"
#include "utility/logging/ConsoleLogger.h"

#include "parsing/FlightFileParser.h"
#include "parsing/FlightParser.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// We'll create a new Cinder Application by deriving from the AppBasic class
class FlightDataRenderer : public AppBasic
{
public:
	void prepareSettings(Settings* settings);
	void setup();
	void mouseDown(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void keyDown(KeyEvent event);
	void update();
	void draw();

private:
	// This will maintain a list of points which we will draw line segments between
	list<Vec2f> m_points;

	float m_lastTime;
};

void FlightDataRenderer::prepareSettings(Settings* settings)
{
	FILE* f;
	AllocConsole();
	freopen_s(&f,"CON","w",stdout);
}

void FlightDataRenderer::setup()
{
	m_lastTime = 0.0f;

	LogManager::getInstance()->addLogger(std::make_shared<ConsoleLogger>());

	FlightFileParser::parseFile("data/flights/jsonTest.txt");
}

void FlightDataRenderer::mouseDown(MouseEvent event)
{
}

void FlightDataRenderer::mouseDrag(MouseEvent event)
{
	//m_points.push_back(event.getPos());
}

void FlightDataRenderer::keyDown(KeyEvent event)
{
	if( event.getChar() == 'f' )
	{
		setFullScreen(!isFullScreen());
	}
}

void FlightDataRenderer::update()
{
	float currentTime = ci::app::getElapsedSeconds();
	float deltaTime = currentTime - m_lastTime;
	m_lastTime = currentTime;
}

void FlightDataRenderer::draw()
{
	gl::clear(Color(0.4f, 0.4f, 0.7f));

	gl::color(1.0f, 0.5f, 0.25f);
	gl::begin(GL_LINE_STRIP);

	for(auto pointIter = m_points.begin(); pointIter != m_points.end(); ++pointIter)
	{
		gl::vertex( *pointIter );
	}

	gl::end();
}

// This line tells Cinder to actually create the application
CINDER_APP_BASIC( FlightDataRenderer, RendererGl )
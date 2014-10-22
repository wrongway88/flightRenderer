#include "cinder/app/AppBasic.h"
#include <list>
#include <memory>

#include "cinder/Vector.h"
#include "cinder/MayaCamUI.h"

#include "Defines.h"

#include "utility/logging/logging.h"
#include "utility/logging/ConsoleLogger.h"

#include "view/IFlightViewer.h"
#include "view/FlightViewerSimple.h"
#include "parsing/FlightFileParser.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// We'll create a new Cinder Application by deriving from the AppBasic class
class FlightDataRenderer : public AppBasic
{
public:
	void prepareSettings(Settings* settings);
	void setup();
	void mouseMove(MouseEvent event);
	void mouseDown(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void keyDown(KeyEvent event);
	void update();
	void draw();

private:
	// This will maintain a list of points which we will draw line segments between
	list<Vec2f> m_points;

	float m_lastTime;

	std::shared_ptr<IFlightViewer> m_flightViewer;

	ci::MayaCamUI m_mayaCamera;
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

	CameraPersp cam;
	cam.setEyePoint( ci::Vec3f(5.0f, 10.0f, 100.0f) );
	cam.setCenterOfInterestPoint( ci::Vec3f(0.0f, 0.0f, 0.0f) );
	cam.setPerspective( 60.0f, getWindowAspectRatio(), 1.0f, 100000.0f );
	m_mayaCamera.setCurrentCam( cam );

	m_flightViewer = std::make_shared<FlightViewerSimple>(FlightFileParser::parseFile("data/flights/flight_18-9_16-41.txt"));
}

void FlightDataRenderer::mouseMove(MouseEvent event)
{
}

void FlightDataRenderer::mouseDown(MouseEvent event)
{
	m_mayaCamera.mouseDown(event.getPos());
}

void FlightDataRenderer::mouseDrag(MouseEvent event)
{
	m_mayaCamera.mouseDrag(event.getPos(), event.isLeftDown(), event.isMiddleDown(), event.isRightDown());

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
	/*gl::begin(GL_LINE_STRIP);

	for(auto pointIter = m_points.begin(); pointIter != m_points.end(); ++pointIter)
	{
		gl::vertex( *pointIter );
	}

	gl::end();*/

	gl::pushMatrices();
	gl::setMatrices(m_mayaCamera.getCamera());

	gl::enableDepthRead();
	gl::enableDepthWrite();

	m_flightViewer->draw();

	gl::popMatrices();
}

// This line tells Cinder to actually create the application
CINDER_APP_BASIC( FlightDataRenderer, RendererGl )
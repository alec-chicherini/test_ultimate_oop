#include <QPainter>
static int num_of_object = 0;
static const int MAX_VALUE = 25;

struct object
{
	object() 
	{
		QPair<int,int> coords = getNiceXY();
		x = coords.first;
		y = coords.second;
	}
	
	QPair<int, int> getNiceXY()
	{
		int x = num_of_object % 3;
		int y = num_of_object / 3;
		num_of_object++;
		return std::make_pair(x * MAX_VALUE, y * MAX_VALUE);
	}

	virtual void draw();
	int x;
	int y;
};

struct circle : public object
{
	circle(QPainter* parent, int radius)
	{
		R = (radius * 2 > MAX_VALUE) ? MAX_VALUE : radius;
		p = parent;
	}

	void draw() override
	{
		p->drawEllipse(x, y, R, R);
	}

private:
	int R;
	QPainter * p;
};

template<int EDGES>
struct polygon : public object
{
	polygon(int edges = EDGES)
	{
		E = edges;
	};

	int numOfEdges()
	{
		return E;
	};

private:
	int E;
};

struct tetragon : public polygon<4>
{
	tetragon(QPainter* parent, int width, int height)
	{
		W = (width > MAX_VALUE)  ? MAX_VALUE : width;
		H = (height > MAX_VALUE) ? MAX_VALUE : height;
		p = parent;
	};

	void draw() override
	{
		p->drawRect(x, y, W, H);
	};

private:
	QPainter* p;
	int W ;
	int H ;
};

/// ------
/// \    /
///  \  /
///   \/
struct triangle : public polygon<3>
{
	triangle(QPainter* parent, int edge)
	{
		E = (edge > MAX_VALUE) ? MAX_VALUE : edge;
	};

	void draw() override
	{
		const float height_equivalent_triangle = float(E) * sqrt(3) / 2.0f;

		QPainterPath pp;
		pp.moveTo(x, y);
		pp.moveTo(x + edge, y);
		pp.moveTo(float(x) - float(edge) / 2.f, float(y) + height_equivalent_triangle);
		pp.moveTo(x, y);

		p.fillPath(pp);
	};
private:
	int E;
	QPainter* p;
};

struct square : public polygon<4>
{
	square(QPainter* parent, int edge)
	{
		E = (edge > MAX_VALUE) ? MAX_VALUE : edge;
		
	};
	void draw() override
	{
		p->drawRect(x, y, E, E);
	};
private:
	int E;
	QPainter* p;
};

class oop
{
	QPainter p;

	QList<object> scene;
	scene.push_back(circle(&p, 15));
	scene.push_back(triangle(&p, 10));
	scene.push_back(tetragon(&p, 10, 20));
	scene.push_back(square(&p, 15));

	foreach(object o, scene) o.draw();
	
};
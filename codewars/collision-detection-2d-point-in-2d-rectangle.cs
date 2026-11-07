/*

Overview
Collision detection is an important mechanic in many applications, specifically in the field of game development. For example, detecting when a player enters some sort of bounding box may be useful to trigger certain events.

For the purpose of this Kata, the user will be asked to create an algorithm which detects if a point in 2D space is contained within a 2D rectangle. A point which is on the edge of the rectangle is not considered a collision.

Technical Information
Points are made up of an X and Y coordinate.

Rectangles consist of rotation information (clockwise, in radians), the X width, the Y width, and a Point representing the center of the rectangle.

Source code:

using System;

namespace Kata
{
  public struct Point2
  {
    public float X;
    public float Y;
    
    public Point2(float pX, float pY)
    {
      this.X = pX;
      this.Y = pY;
    }
    
    public static Point2 operator-(Point2 p1, Point2 p2)
    {
      return new Point2(p1.X - p2.X, p1.Y - p2.Y);
    }
    
    public static Point2 operator+(Point2 p1, Point2 p2)
    {
      return new Point2(p1.X + p2.X, p1.Y + p2.Y);
    }
  }

  public class Rectangle2
  {
    public float Rotation;
    public float WidthX;
    public float WidthY;
    public Point2 Position;
  
    public Rectangle2(float pR, float pWX, float pWY, Point2 pP)
    {
      this.Rotation = pR;
      this.WidthX = pWX;
      this.WidthY = pWY;
      this.Position = pP;
    }
  }
}

Explanatory diagram:
https://imgur.com/aWAJlx3

*/

using System;

public struct Point2
{
	public float X;
	public float Y;

	public Point2(float x, float y)
	{
		this.X = x;
		this.Y = y;
	}

	public static Point2 operator-(Point2 p1, Point2 p2)
	{
		return new Point2(p1.X - p2.X, p1.Y - p2.Y);
	}
    
	public static Point2 operator+(Point2 p1, Point2 p2)
	{
		return new Point2(p1.X + p2.X, p1.Y + p2.Y);
	}
}

public struct Rectangle2
{
	public float Rotation;
	public float WidthX;
	public float WidthY;
	public Point2 Position;

	public Rectangle2(float rotation, float widthX, float widthY, Point2 position)
	{
		this.Rotation = rotation;
		this.WidthX = widthX;
		this.WidthY = widthY;
		this.Position = position;
	}

	public float XMin
	{
		get => Position.X - WidthX/2;
	}

	public float XMax
	{
		get => Position.X + WidthX/2;
	}

	public float YMin
	{
		get => Position.Y - WidthY/2;
	}

	public float YMax
	{
		get => Position.Y + WidthY/2;
	}

	// https://stackoverflow.com/questions/53907352/2d-rotated-rectangle-contains-point-calculation
	public bool Contains(Point2 point)
	{
		// rotate around rectangle center by rectangle rotation angle
		var sin = MathF.Sin(Rotation);
		var cos = MathF.Cos(Rotation);

		// set origin to rect center
		var newPoint = point - Position;
		// rotate
		newPoint = new Point2(newPoint.X*cos - newPoint.Y*sin, newPoint.X*sin + newPoint.Y*cos);
		// put origin back
		newPoint = newPoint + Position;

		// check if our transformed point is in the rectangle, which is no longer
		// rotated relative to the point
		return newPoint.X > XMin && newPoint.X < XMax && newPoint.Y > YMin && newPoint.Y < YMax;
	}
}

class Program
{
	static void Main(String[] args)
	{
		var r = new Rectangle2(0f, 10f, 8f, new Point2(1f, 1f));
		var p = new Point2(-6f, -6f);
		Console.WriteLine(r.Contains(p) == false);

		p = new Point2(-3.5f, 4.5f);
		Console.WriteLine(r.Contains(p) == true);
	
		p = new Point2(-3.5f, 5.0f);
		Console.WriteLine(r.Contains(p) == false);

		r = new Rectangle2((float)(45 * (Math.PI / 180.0f)), 4f, 6f, new Point2(2f, 3f));
		p = new Point2(-1f, 4f);
		Console.WriteLine(r.Contains(p) == false);

		p = new Point2(0.5f, 5f);
		Console.WriteLine(r.Contains(p) == false);

		p = new Point2(1.5f, 5.5f);
		Console.WriteLine(r.Contains(p) == false);

		p = new Point2(-1, 2.5f);
		Console.WriteLine(r.Contains(p) == true);

		p = new Point2(2.5f, 6.2f);
		Console.WriteLine(r.Contains(p) == true);
	}
}


#define PI 3.14159265358979323846f
#define TwoPI (2.f * PI)
#define HalfPI 1.57079632679f
//inverse of PI == PI / 1
#define InvPI   0.31830988618f

//degree ---> radian.
float deg2rad(float indegree)
{
	return indegree * PI / 180.f;
}

void    get_sin_cos(float* outcos, float* outsin, float indegree)
{
    if (indegree == 0.f)
    {
        *outsin = 0.f;
        *outcos = 1.f;
    }
    else if (indegree == 90.f)
    {
        *outcos = 0.f;
        *outsin = 1.f;
    }
    else if (indegree == 180.f)
    {
        *outsin = 0.f;
	    *outcos = -1.f;
    }
    else if (indegree == 270.f)
    {
        *outsin = -1.f;
        *outcos = 0.f;
    }
    else
    {
        get_sin_cos_rad(outcos, outsin, deg2rad(indegree));
    }
}


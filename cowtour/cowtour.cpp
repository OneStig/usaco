struct Point
{
    int x, y;
};


int n;
double dist[160][160];
double diam[160];
double fielddiam[160];
Point pt[160];
int field[160];
int nfield;

double
ptdist(Point a, Point b)
{
    return sqrt((double)(b.x - a.x) * (b.x - a.x) + (double)(b.y - a.y) * (b.y - a.y));
}

void mark(int i, int m)
{
    int j;
    if (field[i] != -1)
    {
        return;
    }

    field[i] = m;
    for (j = 0; j < n; j++)
        if (dist[i][j] < INF / 2)
            mark(j, m);
}

int main()
{
    int i, j, k, c;
    double newdiam, d;


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c = getc(fin);
            if (i == j)
                dist[i][j] = 0;
            else if (c == '0')
                dist[i][j] = INF; /* a lot */
            else
                dist[i][j] = ptdist(pt[i], pt[j]);
        }
    }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (i = 0; i < n; i++)
        field[i] = -1;
    for (i = 0; i < n; i++)
        if (field[i] == -1)
            mark(i, nfield++);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (diam[i] < dist[i][j] && dist[i][j] < INF / 2)
                diam[i] = dist[i][j];
        if (diam[i] > fielddiam[field[i]])
            fielddiam[field[i]] = diam[i];
    }

    newdiam = INF;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (field[i] == field[j])
                continue;

            d = diam[i] + diam[j] + ptdist(pt[i], pt[j]);
            if (d < fielddiam[field[i]])
                d = fielddiam[field[i]];
            if (d < fielddiam[field[j]])
                d = fielddiam[field[j]];

            if (d < newdiam)
                newdiam = d;
        }
}
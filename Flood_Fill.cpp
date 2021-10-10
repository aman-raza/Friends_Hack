/*
 * Author : Umesh Kumar
 * Date : 06/10/2021
 * Problem : https://leetcode.com/problems/flood-fill/
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &img, int sr, int sc, int src, int newColor)
{
    if (img[sr][sc] != src)
        return;

    img[sr][sc] = newColor;
    // top
    if (sr - 1 >= 0)
        dfs(img, sr - 1, sc, src, newColor);
    // bottom
    if (sr + 1 < img.size())
        dfs(img, sr + 1, sc, src, newColor);
    // left
    if (sc - 1 >= 0)
        dfs(img, sr, sc - 1, src, newColor);
    // right
    if (sc + 1 < img[0].size())
        dfs(img, sr, sc + 1, src, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // if src == newColor, then all the associated grid will of same then no change
    if (image[sr][sc] == newColor)
        return image;
    dfs(image, sr, sc, image[sr][sc], newColor);
    return image;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    for (auto e : floodFill(image, sr, sc, newColor))
    {
        for (auto a : e)
            cout << a << " ";
        cout << endl;
    }
    image = {{0, 0, 0}, {0, 0, 0}}, sr = 0, sc = 0, newColor = 2;
    for (auto e : floodFill(image, sr, sc, newColor))
    {
        for (auto a : e)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
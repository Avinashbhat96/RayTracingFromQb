#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Image
{
    public:
    Image();
    ~Image();

    void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);

    void SetPixel(const int x, const int y, const double red, const double green, const double blue);

    void Display();

    inline int GetXSize(){ return m_xSize; };

    inline int GetYSize(){ return m_ySize; };

    private:
    Uint32 ConvertColor(const double red, const double green, const double blue);
    void InitTexture();
    private:
    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;

    int m_xSize, m_ySize;

    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
};

#endif // IMAGE_HPP
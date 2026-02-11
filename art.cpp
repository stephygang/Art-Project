// UMBC - CMSC 341 - Spring 2026 - Proj0
#include "art.h"
Art::Art(){
    m_height = m_width = 0;
    m_painting = nullptr;
}
Art::Art(int height, int width){
    if (height <= 0 || width <= 0) {
        m_height = 0;
        m_width = 0;
        m_painting = nullptr;
    } //endif
    else if (height == 1 && width == 1) {
        m_height = m_width = 0;
        m_painting = nullptr;
    }
    else {
        m_height = height;
        m_width = width;

        m_painting = new int*[m_height];
        for (int i=0;i<m_height;i++) {
            //int array pointer of size m_width
            m_painting[i] = new int[m_width];
            //initialize each int array to 0
            for (int j=0;j<m_width;j++) {
                m_painting[i][j] = 0;
            } //end for2
        } //end for1

    } //endelse

}

Art::~Art(){
    clear();
}

void Art::clear() {
    //check if m_painting is emtpy
    if (m_height <= 0 && m_width <= 0 && m_painting == nullptr) {
        return;
    } //endif

    else {
        if (m_painting != nullptr) {
            for (int i=0;i<m_height;i++)
                delete[] m_painting[i];

            //delete the entire m_painting
            delete[] m_painting;

            m_painting = nullptr;
            m_width = m_height = 0;
        }
    } //endelse
}

void Art::create(int initiate){

    Random rand(10, 99);
    rand.setSeed(initiate);

    if (m_painting != nullptr) {
        for (int i = 0;i < m_height;i++) {
            for (int j = 0;j < m_width;j++) {

                //generate random color code and inserts it into m_painting
                m_painting[i][j] = rand.getRandNum();

            } //end for1
        } //end for2
    } //endif

}

void Art::dumpColors(string pixel) const{
    if (m_height > 0 && m_width > 0 && m_painting != nullptr){
        for (int i=0;i < m_height;i++){
            for (int j=0;j<m_width;j++){
                std::cout << "\x1b[38;5;" << to_string(m_painting[i][j]) << "m" << pixel << pixel << RESET;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Art::dumpValues() const{
    if (m_height > 0 && m_width > 0 && m_painting != nullptr){
        for (int i=0;i < m_height;i++){
            for (int j=0;j<m_width;j++){
                cout << m_painting[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

Art::Art(const Art& rhs){

    if (rhs.m_painting == nullptr) {
        return;
    }

    else {
        m_height =rhs.m_height;
        m_width  = rhs.m_width;
        m_painting = new int*[m_height];

        for (int i = 0; i < m_height; i++) {
            m_painting[i] = new int[m_width];

            for (int j = 0; j < m_width; j++) {
                m_painting[i][j] = rhs.m_painting[i][j];

            } //end for2

        } //end for1
    }

}

const Art& Art::operator=(const Art& rhs){

    if (this == &rhs) {

        return *this;

    } //endif

    if (this == nullptr) { return *this; }

    clear();

    m_height = rhs.m_height;
    m_width  = rhs.m_width;

    if (rhs.m_painting == nullptr) {

        m_painting = nullptr;
        return *this;

    } //endif

    m_painting = new int*[m_height];

    for (int i = 0; i < m_height; i++) {
        m_painting[i] = new int[m_width];

        for (int j = 0; j < m_width; j++) {
            m_painting[i][j] = rhs.m_painting[i][j];

        } //end for2

    } //end for1

    return *this;

}

bool Art::left2Right(const Art& rhs){

    // do nothing if rhs empty
    if (rhs.m_painting == nullptr) {
        return true;
    }

    // copy if this empty
    if (m_painting == nullptr) {
        *this = rhs;
        return true;
    }

    // check heights are equal
    if (m_height != rhs.m_height) {
        return false;
    }

    int newHeight = m_height;
    int newWidth  = m_width + rhs.m_width;

    // allocate
    int** newPainting = new int*[newHeight];

    for (int i = 0; i < newHeight; i++) {
        newPainting[i] = new int[newWidth];

        // Copy this
        for (int j = 0; j < m_width; j++) {
            newPainting[i][j] = m_painting[i][j];
        }

        // Copy rhs
        for (int j = 0; j < rhs.m_width; j++) {
            newPainting[i][j + m_width] = rhs.m_painting[i][j];
        }
    }

    // Delete old painting
    clear();

    m_painting = newPainting;
    m_height   = newHeight;
    m_width    = newWidth;

    return true;

}

bool Art::top2Bottom(const Art& bottom){

    if (bottom.m_painting == nullptr) {
        return true;
    }

    if (m_painting == nullptr) {
        *this = bottom;
        return true;
    }

    if (m_width != bottom.m_width) {
        return false;
    }

    int newHeight = m_height + bottom.m_height;
    int newWidth  = m_width;

    int** newPainting = new int*[newHeight];

    // Copy old painting
    for (int i = 0; i < m_height; i++) {
        newPainting[i] = new int[newWidth];
        for (int j = 0; j < newWidth; j++) {
            newPainting[i][j] = m_painting[i][j];
        }
    }

    // Copy bottom painting
    for (int i = 0; i < bottom.m_height; i++) {
        newPainting[i + m_height] = new int[newWidth];
        for (int j = 0; j < newWidth; j++) {
            newPainting[i + m_height][j] = bottom.m_painting[i][j];
        }
    }

    // Delete old painting
    clear();

    m_painting = newPainting;
    m_height   = newHeight;
    m_width    = newWidth;

    return true;

}

bool Art::reverse() {
    return true;
}

bool Art::rotate(){
    return true;

}

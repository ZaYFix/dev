template<class T>
FileT<T>::FileT(int capacite): capacite(capacite), in (0), out(0)
{
    this->taille = 0;
    t = new T[capacite];
    for (int i = 0; i < capacite; i++)
        t[i] = 0;
}

template<class T>
FileT<T>::~FileT()
{
    delete[] t;
}

template<class T>
FileT<T>::FileT(const FileT &fi)
{
    cout << "FileT::FileT(const FileT &fi)" << endl;
    this->taille = fi.taille;
    this->capacite = fi.capacite;
    this->t = new T[fi.capacite];
    for (int i = 0; i < fi.capacite; i++)
        this->t[i] = fi.t[i];
    this->in = fi.in;
    this->out = fi.out;
}

template<class T>
T& FileT<T>::operator=(const FileT<T> &fi)
{
    if (this != &fi)
    {
        delete[] t;
        taille = fi.taille;
        capacite = fi.capacite;
        t = new T[fi.capacite];
        for (int i = 0; i < fi.capacite; i++)
            t[i] = fi.t[i];
        this->in = fi.in;
        this->out = fi.out;
    }
    return *this;
}

template<class T>
void FileT<T>::operator+(const T ajoutEntierALaFile) throw()
{
    if (this->taille >= this->capacite)
        throw FileException("FileT pleine");
    this->t[this->in] = ajoutEntierALaFile;
    this->taille++;
    this->in = (this->in + 1) % this->capacite;
}

template<class T>
T& FileT<T>::operator-() throw()
{
    if (this->taille == 0)
        throw FileException("FileT vide");
    this->taille--;
    this->out = (this->out + 1) % this->capacite;
    return this->t[this->out];
}

template<class T>
void FileT<T>::affiche()
{
    cout << "FileT : " << *this << endl;
}

template<class T>
ostream& operator<<(ostream &os, const FileT<T> &fi)
{
    int nb = 0;
    if (fi.taille > 0)
    {
        os << "<" << fi.taille << "/" << fi.capacite << ">";
        os << " [" << fi.in << "," << fi.out << "] ";
        os << "{";
        for (int i = fi.out; i < (fi.out + fi.taille); i++)
        {
            nb++;
            if (nb == 1)
                os << fi.t[i % fi.capacite];
            else
                os << ", " << fi.t[i % fi.capacite];
        }
        os << "}";
    }
    else
        os << "{"
            << "}";
    return os;
}
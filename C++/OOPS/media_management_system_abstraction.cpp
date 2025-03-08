// Design a digital media library that manages different types of media content. Create an abstract MediaItem class with common properties and behaviors that all media items should have. Then implement concrete classes for specific media types like Song, Movie, and Ebook.
// Requirements:

// The MediaItem class should be abstract with properties like title, creator, and release date
// Each media type should implement abstract methods like play(), displayInfo(), and getFileSize()
// Song should track duration, genre, and album
// Movie should track duration, director, and rating
// Ebook should track page count, format, and publisher
// Create a media library that can store and manage different types of media items


#include<iostream>

using namespace std;

class media{
    private:
        string title;
        int release_month;
        string creator;

    public:
        media(string title, int month, string creator)
        {
            this -> title = title;
            this ->release_month = month;
            this -> creator = creator;
        }

        virtual void getDuration() const = 0;

        virtual void getGenre() const = 0;
        
};

class song : public media{
    private:
        string genre;
        int duration;

    public:
        song(string title, int month, string creator, int duration, string genre) : media(title, month, creator)
        {
            this -> genre = genre;
            this -> duration = duration;
        }

        void getDuration() const override{
            cout << this -> duration << " min" << endl;
        }

        void getGenre() const override{
            cout << this -> genre << endl;
        }
};

int main()
{
    song baby("Baby", 5, "Justin Beiber", 3, "Song");

    media *m = &baby;

    m->getDuration();
    m->getGenre();

}
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>


class Track {

public:

    std::string GetName()
    {
        return name_;
    }

    std::tm GetDate()
    {
        return date_;
    }

    int GetDuration()
    {
        return duration_;
    }

    void SetName(std::string name)
    {
        name_ = name;
    }

    void SetDate(int day, int month)
    {
        if (day < 0) date_.tm_mday = 1;
        else if (day > 31) date_.tm_mday = 31;
        else date_.tm_mday = day;

        if (month < 1) date_.tm_mon = 0;
        else if (month > 12) date_.tm_mon = 11;
        else date_.tm_mon = month - 1;
    }

    void SetDuration(int duration) 
    {
        duration_ = duration;
    }

private:

    std::string name_;
    std::tm date_;
    int duration_;
};


class Player {

public:

    void Play() {

        if(!PlayerMemory()) {
            std::cout<<"There are no tracks in the player's memory\n";
            return;
        }

        if (!isPause_) {
            std::string name;
            std::cout<<"Enter the name of the recording to play: ";
            std::cin.ignore();
            getline(std::cin, name);

            if(!names_.count(name)) {
                std::cout<<"The track with the specified name is missing\n";
                return;
            }
            
            isPlay_ = true;
            play_name = name;
            PlayName(name);

        } else {
            PlayName(play_name);
        }
    }

    void Stop() {

        if(isPlay_ || isPause_) {
            isPlay_ = false;
            isPause_ = false;
            play_name = "";
            std::cout<<"\nStopping playback of the current track\n";
        } else {
            return;
        }      
    }    

    void Pause() {

        if(isPlay_) {
            isPlay_ = false;
            isPause_ = true;
            std::cout<<"\nPause track playback\n";
        }       
    }    

    void Next() {

        if(!PlayerMemory()) {
            std::cout<<"There are no tracks in the player's memory\n";
            return;
        }

        std::srand(time(nullptr));
        int index = rand() % (num_records_.size());
        Track tr = num_records_[index];
        isPlay_ = true;
        play_name = tr.GetName();

        std::cout<<"\nPlaying track number "<<index<<"\n"
        <<"Track name - "<<play_name
        <<"  date - "<<tr.GetDate().tm_mday<<"."<<tr.GetDate().tm_mon
        <<"  duration - "<<tr.GetDuration()<<"\n";
    }


    void ListingTracks() {
        
        std::cout<<"\nTrack listing:\n";
        for (auto [k, v] : num_records_) {
            tm d = v.GetDate();
            std::cout<<"number: "<<k<<"  name: "<<v.GetName()
            //<<"  date: "<<v.GetDate().tm_mday<<"."<<v.GetDate().tm_mon
            <<"  date: "<<std::put_time(&d, "%d.%m")
            <<" duration: "<<v.GetDuration()<<"\n";
        }
   
    }

    

    void FillPlayer() {
        
        std::string name;
        int n, num_track;
        std::cout<<"Enter the number of tracks: ";
        std::cin>>n;

        for (int i = 0; i < n; ++i) {
            Track tr;
            
            do {   
                std::cout<<"Enter information about the track number "<< i + 1 <<":\n";
                tr = AddTrack();
                name = tr.GetName();
                if (names_.count(name))
                    std::cout<<"\nThe track with the specified name "
                    <<"is already present in memory\n";
            } while (names_.count(name)); 

            num_track = num_records_.size();
            num_records_[num_track] = tr;
            names_[name] = num_track;
        } 
    }



private:

    Track AddTrack() {

        std::string name;
        int duration, day, month;
        Track tr;
        
        std::cout<<"Enter the name: ";
        std::cin.ignore();
        getline(std::cin, name);
        std::cout<<"Enter the date and month:\n";
        std::cin>>day>>month;
        std::cout<<"Enter the duration: ";
        std::cin>>duration;

        tr.SetName(name);
        tr.SetDate(day, month);
        tr.SetDuration(duration);

        return tr;
    }

    void PlayName(std::string name) {
      
        int num_track = names_[name];
        Track tr = num_records_[num_track];
        std::cout<<"\nPlaying track number "<<num_track<<"\n"
        <<"Track name - "<<tr.GetName()
        <<"  date - "<<tr.GetDate().tm_mday<<"."<<tr.GetDate().tm_mon
        <<"  duration - "<<tr.GetDuration()<<"\n";
        
    }

    bool PlayerMemory() {

        return num_records_.size() > 0;
    }


    bool isPlay_ = false;
    bool isPause_ = false;
    std::string play_name;
    std::map<int, Track> num_records_;
    std::map<std::string, int> names_;
};





int main() {

    Player* pl = new Player();
    std::cout<<"Filling the player's memory with tracks\n";
    pl->FillPlayer();

    std::cout<<"\nPlayer Start!\n";
    std::string oper;

    while(true) {

        std::cout<<"Enter the name of the operation: ";
        std::cin>>oper;

        if (oper == "play" ) {
            pl->Play();

        } else if (oper == "stop") {
            pl->Stop();
        
        } else if (oper == "pause") {
            pl->Pause();

        } else if (oper == "next") {
            pl->Next();

        } else if (oper == "list") {
            pl->ListingTracks();

        } else if (oper == "exit") {
            std::cout<<"Turning off the player";
            delete pl;
            pl = nullptr;
            return 0;

        } else {
            std::cout<<"\nWrong command!\n";
        }
    }

    return 1;
}




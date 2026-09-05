#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <vector>

class Post{
private:
    std::string content;
public:
    Post(const std::string& content)
    :  content(content) {}
    void display() {
        std::cout << content << std::endl;
    }

    const std::string& returnContent() {
        return content;
    }
};

class User {
private:
    std::string name;
    //std::string id;
    int idNum = 0;
    std::vector<std::shared_ptr<Post>> posts;
    std::vector<std::weak_ptr<User>> friends;
public:
    User(std::string name)
        : name(name), idNum(idNum)
    {
        std::cout << "User created" << std::endl;
    }

    ~User() {
        std::cout << "Destroyed" << std::endl;
    };

    const void addPost(std::shared_ptr<Post> post) {
        posts.emplace_back(post);
    }

    const void returnPosts() {
        for (const auto& post : posts) {
            std::cout << name << ": " << post->returnContent() << std::endl;
        }
    }

    const void returnFriends() {
        std::cout << name << "'s friends:" << std::endl;
        for (const auto& fr : friends) {
            if (auto ptr = fr.lock()) {
                std::cout << ptr->returnName() << std::endl;
            }
            else {
                std::cout << "nada" << std::endl;
            }
        }
    }

    const std::string& returnName() const {
        return name;
    }

    const int returnID() const {
        std::cout << idNum;
        return idNum;
    }

    const int numPosts() const {
        return posts.size();
    }

    std::vector<std::weak_ptr<User>>& getFlist() {
        return friends;
    }
};

struct Network {
    static std::vector<std::shared_ptr<User>> users;

    static void createAccount(const std::string& iName) {
        users.emplace_back(std::make_shared<User>(iName));
        return;
    }
    static void deleteAccount(const std::string& iName) {
        for (auto i = users.begin(); i < users.end(); ++i) {
            if ((*i)->returnName() == iName) {
                users.erase(i);
                return;
            }
        }
    }

    static std::shared_ptr<Post> createPost(const std::string& content) {
        return std::make_shared<Post>(content);
    }

    static void addFriend(const std::string& name1, const std::string& name2) {
        auto user1 = Network::returnUser(name1);
        auto user2 = Network::returnUser(name2);
        user1->getFlist().emplace_back(user2);
        user2->getFlist().emplace_back(user1);
        std::cout << name1 << " and " << name2 << " are friends." << std::endl;
    }

    static void removeFriend(const std::string& name1, const std::string& name2) {
        auto user1 = Network::returnUser(name1);
        auto user2 = Network::returnUser(name2);
        for (auto i = user1->getFlist().begin(); i < user1->getFlist().end(); ++i) {
            if (i->lock()->returnName() == name2) {
                user1->getFlist().erase(i);
                break;
            }
        }
        for (auto i = user2->getFlist().begin(); i < user2->getFlist().end(); ++i) {
            if (i->lock()->returnName() == name1) {
                user2->getFlist().erase(i);
                break;
            }
        }
        std::cout << name1 << " and " << name2 << " are no longer friends" << std::endl;
    }

    const static void returnVec() { //Returns names of every user in users
        for (const auto& user : users) {
            std::cout << user->returnName();
        }
        //return users;
    }

    const static std::shared_ptr<User> returnUser(const std::string& iName) {
        for (const auto& user : users) {
            if(user->returnName() == iName) {
                return user;
            }
        }
        return nullptr;
    }

    const static void printNetwork() {
        std::cout << "----- Network -----" << std::endl;
        for (auto& user : users) {
            std::cout << user->returnName() << std::endl;
            std::cout << "  Friends: ";
            for (std::weak_ptr<User>& fr : user->getFlist()) {
                if (const auto& ptr = fr.lock()) {
                    std::cout << ptr->returnName() << " ";
                }
                
            }
            std::cout << "\n  Posts: " << user->numPosts() << std::endl;
        }
    }
};

std::vector<std::shared_ptr<User>> Network::users;

int main() {
    Network::users;
    std::cout << "Welcome to the Social Network!" << std::endl;
    std::string line;
    std::string word1, word2, word3;
    while (word1 != "end") {
        std::cout << "Enter a command followed by any user(s) included: ";
        std::getline(std::cin, line); //grabs line
        std::istringstream iss(line); //setting cin from the line
        iss >> word1 >> word2;  //parses first 2 values to 'c' and 'd'
        if (word1 == "end") {
            break;
        }
        if (iss >> word3) {
            if (word1 == "friend") {
                Network::addFriend(word2, word3);
            }
            else if (word1 == "unfriend") {
                Network::removeFriend(word2, word3);
            }
            else if (word1 == "post") {
                //Make it so all posts from friends show up
                Network::returnUser(word2)->addPost(Network::createPost(word3));
            }
            else {
                std::cout << "Invalid input, try again!" << std::endl;
            }
        }
        else {
            if (word1 == "create"){
                Network::createAccount(word2);
            }
            else if (word1 == "delete"){
                Network::deleteAccount(word2);
            }
            else if (word1 == "friends"){
                Network::returnUser(word2)->returnFriends();
            }
            else if (word1 == "posts"){
                Network::returnUser(word2)->returnPosts();
            }
            else if (word1 == "network"){
                Network::printNetwork();
            }
            else {std::cout << "Invalid input, try again!" << std::endl;}
        }
    }
    Network::returnVec();
    return 0;
}
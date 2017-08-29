#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/Chat.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chat::Chat(int id, chat_type type) : id(id), type (type)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Chat::setTitle(const optional<string> &title) {
    Chat::title = title;
}

void Chat::setUsername(const optional<string> &username) {
    Chat::username = username;
}

void Chat::setFirst_name(const optional<string> &first_name) {
    Chat::first_name = first_name;
}

void Chat::setLast_name(const optional<string> &last_name) {
    Chat::last_name = last_name;
}

void Chat::setAll_members_are_administrators(const optional<bool> &all_members_are_administrators) {
    Chat::all_members_are_administrators = all_members_are_administrators;
}

void Chat::setDescription(const optional<string> &description) {
    Chat::description = description;
}

void Chat::setInvite_link(const optional<string> &invite_link) {
    Chat::invite_link = invite_link;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Chat::getId() const {
    return id;
}

chat_type Chat::getType() const {
    return type;
}

const optional<string> &Chat::getTitle() const {
    return title;
}

const optional<string> &Chat::getUsername() const {
    return username;
}

const optional<string> &Chat::getFirst_name() const {
    return first_name;
}

const optional<string> &Chat::getLast_name() const {
    return last_name;
}

const optional<bool> &Chat::getAll_members_are_administrators() const {
    return all_members_are_administrators;
}

const optional<string> &Chat::getDescription() const {
    return description;
}

const optional<string> &Chat::getInvite_link() const {
    return invite_link;
}
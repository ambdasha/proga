#include "client_bst.hpp"
#include <iostream>

ClientBST::ClientBST() : root(nullptr) {}

ClientBST::~ClientBST() {
    clearHelper(root);
}

void ClientBST::clearHelper(ClientNode* node) {
    if (node) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}

void ClientBST::insert(shared_ptr<Client> client) {
    if (!client) return;
    insertHelper(root, client);
}

void ClientBST::insertHelper(ClientNode*& node, shared_ptr<Client> client) {
    if (!node) {
        node = new ClientNode(client);
    }
    else if (client->getId() < node->data->getId()) {
        insertHelper(node->left, client);
    }
    else if (client->getId() > node->data->getId()) {
        insertHelper(node->right, client);
    }
    // Если ID уже существует, ничего не делаем (или можно обновить данные)
}

shared_ptr<Client> ClientBST::find(const string& id) const {
    ClientNode* found = findHelper(root, id);
    return found ? found->data : nullptr;
}

ClientNode* ClientBST::findHelper(ClientNode* node, const string& id) const {
    if (!node) return nullptr;
    if (id == node->data->getId()) return node;
    if (id < node->data->getId()) return findHelper(node->left, id);
    return findHelper(node->right, id);
}

vector<shared_ptr<Client>> ClientBST::getAllClients() const {
    vector<shared_ptr<Client>> result;
    inOrderHelper(root, result);
    return result;
}

void ClientBST::inOrderHelper(ClientNode* node, vector<shared_ptr<Client>>& result) const {
    if (node) {
        inOrderHelper(node->left, result);
        result.push_back(node->data);
        inOrderHelper(node->right, result);
    }
}

void ClientBST::displayInOrder() const {
    cout << "--- Клиенты (отсортировано по ID) ---" << endl;
    vector<shared_ptr<Client>> clients = getAllClients();
    for (const auto& client : clients) {
        cout << "ID: " << client->getId()
            << ", Имя: " << client->getName()
            << ", Баланс: " << client->getTotalBalance() << endl;
    }
    cout << "-------------------------------------" << endl;
}

ClientNode* ClientBST::findMin(ClientNode* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

bool ClientBST::remove(const string& id) {
    if (!findHelper(root, id)) {
        return false;
    }
    root = removeHelper(root, id);
    return true;
}

ClientNode* ClientBST::removeHelper(ClientNode* node, const string& id) {
    if (!node) return nullptr;

    if (id < node->data->getId()) {
        node->left = removeHelper(node->left, id);
    }
    else if (id > node->data->getId()) {
        node->right = removeHelper(node->right, id);
    }
    else {
        // Узел с одним потомком или без потомков
        if (!node->left) {
            ClientNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            ClientNode* temp = node->left;
            delete node;
            return temp;
        }

        // Узел с двумя потомками
        ClientNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeHelper(node->right, temp->data->getId());
    }
    return node;
}
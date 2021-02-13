#include <iostream>
#include <string>

struct flight_req
{
	std::string dest;
	int flight_num;
	std::string initials;
	std::string flight_date;

	flight_req(std::string dest = "", int flight_num = 0,
	std::string initials = "", std::string fligt_date = "")
	{
		this->dest = dest;
		this->flight_num = flight_num;
		this->initials = initials;
		this->flight_date = flight_date;
	}

	void print_req()
	{
		std::cout << "Заявка";
		std::cout << "\nПункт назначения: " << this->dest;
		std::cout << "\nНомер рейса: " << this->flight_num;
		std::cout << "\nФамилия и инициалы пассажира: " << this->initials;
		std::cout << "\nДата вылета: " << this->flight_date;
	}
};

struct req_tree
{
	std::shared_ptr<flight_req> info;
	std::shared_ptr<req_tree> left_subtree;
	std::shared_ptr<req_tree> right_subtree;

	req_tree(flight_req* info)
	{
		this->info = (std::shared_ptr<flight_req>) info;
		this->left_subtree = nullptr;
		this->right_subtree = nullptr;
	}

	void add_req(flight_req* info)
	{
		if (this->info->flight_num <= info->flight_num)
			if (this->right_subtree == nullptr)
			{
				this->right_subtree = (std::shared_ptr<req_tree>) new req_tree(new flight_req());
				this->right_subtree->info->dest = info->dest;
				this->right_subtree->info->flight_num = info->flight_num;
				this->right_subtree->info->initials = info->initials;
				this->right_subtree->info->flight_date = info->flight_date;
			}
			else
				this->right_subtree->add_req(info);
		else
			if (this->left_subtree == nullptr)
			{
				this->left_subtree = (std::shared_ptr<req_tree>) new req_tree(new flight_req());
				this->left_subtree->info->dest = info->dest;
				this->left_subtree->info->flight_num = info->flight_num;
				this->left_subtree->info->initials = info->initials;
				this->left_subtree->info->flight_date = info->flight_date;
			}
			else
				this->left_subtree->add_req(info);
	}

	void delete_req()
	{
		if (this->left_subtree == nullptr)
		{
			std::shared_ptr<req_tree> temp = (std::shared_ptr<req_tree>) this->right_subtree;
			this->info = temp->info;
			this->left_subtree = temp->left_subtree;
			this->right_subtree = temp->right_subtree;
			temp = nullptr;
		}
		else
			if (this->right_subtree == nullptr)
			{
				std::shared_ptr<req_tree> temp = (std::shared_ptr<req_tree>) this->left_subtree;
				this->info = temp->info;
				this->left_subtree = temp->left_subtree;
				this->right_subtree = temp->right_subtree;
				temp = nullptr;
			}
			else
			{
				std::shared_ptr<req_tree> temp = (std::shared_ptr<req_tree>) this->right_subtree;
				if (temp->left_subtree == nullptr)
				{
					this->info = temp->info;
					this->right_subtree = temp->right_subtree;
					temp = nullptr;
				}
				else
				{
					while (temp->left_subtree->left_subtree != nullptr)
						temp = temp->left_subtree;
					this->info = temp->left_subtree->info;
					if (temp->left_subtree->left_subtree == nullptr &&
						temp->left_subtree->right_subtree == nullptr)
						temp->left_subtree = nullptr;
					else
						temp->left_subtree->delete_req();
				}
			}
	}

	void search_reqs(int flight_num, std::string flight_date, bool& leaf)
	{
		if (this == nullptr) return;
		if (flight_num > this->info->flight_num)
		{
			this->right_subtree->search_reqs(flight_num, flight_date, leaf);
			if (leaf)
			{
				this->right_subtree = nullptr;
				leaf = false;
			}
		}
		else
			if (flight_num < this->info->flight_num)
			{
				this->left_subtree->search_reqs(flight_num, flight_date, leaf);
				if (leaf)
				{
					this->left_subtree = nullptr;
					leaf = false;
				}
			}
			else
			{
				if (flight_date == this->info->flight_date)
				{
					this->info->print_req();
					std::cout << "\n\n";
					if (this->left_subtree == nullptr &&
						this->right_subtree == nullptr)
					{
						leaf = true;
						return;
					}
					else
					{
						this->delete_req();
						this->search_reqs(flight_num, flight_date, leaf);
					}
				}
				else
					if (flight_num == this->right_subtree->info->flight_num)
					{
						this->right_subtree->search_reqs(flight_num, flight_date, leaf);
						if (leaf)
						{
							this->right_subtree = nullptr;
							leaf = false;
						}
					}
					else
						return;
			}
	}

	void print_all()
	{
		if (this != nullptr)
		{
			if (this->info->flight_num != 0)
			{
				this->info->print_req();
				std::cout << "\n\n";
			}
			this->left_subtree->print_all();
			this->right_subtree->print_all();
		}
	}

};

int main()
{
	setlocale(0, "rus");

	req_tree root = req_tree(new flight_req());
	flight_req temp = flight_req();

	int n;
	std::cout << "Введите количество заявок: ";
	std::cin >> n;
	std::cout << "\n";


	for (int i = 0; i < n; i++)
	{
		std::cout << "Введите данные заявки";
		std::cout << "\nПункт назначения: ";
		std::cin >> temp.dest;
		std::cout << "Номер рейса: ";
		std::cin >> temp.flight_num;
		std::cout << "Фамилия и инициалы пассажира (без пробелов): ";
		std::cin >> temp.initials;
		std::cout << "Дата вылета (DD.MM.YYYY): ";
		std::cin >> temp.flight_date;
		std::cout << "\n\n";
		root.add_req(&temp);
	}

	std::cout << "Все хранящиеся заявки: \n\n";
	root.print_all();

	int flight_num;
	std::string flight_date;
	std::cout << "Введите номер рейса и дату вылета";
	std::cout << "\nНомер рейса: ";
	std::cin >> flight_num;
	std::cout << "Дата вылета (DD.MM.YYYY): ";
	std::cin >> flight_date;

	std::cout << "\n\nВсе заявки, подходящие под описание: \n\n";
	bool leaf = false;
	root.search_reqs(flight_num, flight_date, leaf);

	std::cout << "\n";
	return 0; 
}

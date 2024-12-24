

#include "ShruberryCreationForm.hpp"


/*
		ShruberryCreationForm(std::string target = "YoMama");
		~ShruberryCreationForm();
		ShruberryCreationForm(const ShruberryCreationForm& obj);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& obj);

		//AForm method inherited
		virtual void		execute(Bureaucrat const & executor);
*/

ShruberryCreationForm::ShruberryCreationForm(const std::string& target) : AForm("ShruberryForm", 145, 137), target(target)
{
	std::cout<<"The shruberry has been created"<<std::endl;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
	std::cout<<"The shruberry got destroyed"<<std::endl;
}

std::string ShruberryCreationForm::getTarget(void) const
{
	return this->target;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& obj) : AForm(obj)  , target(obj.getTarget())
{
	std::cout<<"The copy constructor of shruberry has been called"<<std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& obj)
{
	(void) obj;
	return *this;
}

void ShruberryCreationForm::execute(const Bureaucrat& executor) const
{
	std::string nameFile;
	const char* trueNameFile;

	std::cout<<"Let's see..... is the form executable?"<<std::endl;
	if (this->getSign() == true)
	{
		std::cout<<"It seems that the form is signed now let's see..."<<std::endl;
		if (executor.getGrade() <= 137)
		{
			nameFile = this->getTarget() + "_shruberry";
			trueNameFile = nameFile.c_str();
			std::ofstream file(trueNameFile);
			if (file.is_open())
			{
				file <<"          .     .  .      +     .      .          .         "<<std::endl;
				file <<"     .       .      .     #       .           .             "<<std::endl;
				file <<"        .      .         ###            .      .      .     "<<std::endl;
				file <<"      .      .   \"#:. .:##\"##:. .:#\"  .      .              "<<std::endl;
				file <<"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ."<<std::endl;
				file <<"  .             \"#########\"#########\"        .        .     "<<std::endl;
				file <<"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .        "<<std::endl;
				file <<"     .     .  \"#######\"\"##\"##\"\"#######\"                  .  "<<std::endl;
				file <<"                .\"##\"#####\"#####\"##\"           .      .     "<<std::endl;
				file <<"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .         "<<std::endl;
				file <<"    .    .     \"#####\"\"#######\"\"#####\"    .      .          "<<std::endl;
				file <<"            .     \"      000      \"    .     .              "<<std::endl;
				file <<"       .         .   .   000     .        .       .          "<<std::endl;
				file <<".. .. ..................O000O........................ ......"<<std::endl;
				file.close();
			}
			else
				std::cout<<"Error the file can't be opened"<<std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}

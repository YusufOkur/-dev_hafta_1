#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>

int main()

{
	int seçim1, seçim2, user, parola, yatırma=0, çekme=0, bakiye_19009001=2863, bakiye_19009002=1759, gonderme=0, hatalı;

	setlocale(LC_ALL, "Turkish"); // Türkçe karakterler kullanabilmek için

	while(1) // ilk dönürülmek için
	{
	printf("\t\t\t ÖDEV BANK\n");
	printf("\tGiriş Menüsü\n\n");
	printf("1) Hesap Numaranızı Giriniz\n");
	printf("2) Çıkış\n\n");
	printf("Seçiminiz ? <1-2>:\n\n");
	scanf_s("%d",&seçim1);

	if(seçim1!=1 && seçim1!=2) // 1 veya 2'den farklı bir giriş yaparsa uyarır
	{
		printf("Girişiniz yanlış yaptınız. Lütfen tekrar deneyiniz...\a\n");
		printf("------------------------------------------------\n\n");
	}

			switch(seçim1)
	{
	case 1: // giriş seçeneği seçildiyse..
		system("CLS"); // ekranı temizler

		for(hatalı=1; hatalı<=3;) // 3 yanlış giriş hakkı	
		{
			printf("Lütfen Hesap Bilgilerinizi Giriniz:\n\n");
			printf("Kullanıcı adı: ");
			scanf_s("%d",&user);
			printf("Parola: ");
			scanf_s("%d",&parola);

			printf("\n...Veriler Algılanıyor. . .");
			Sleep(1500);
			printf("\n\n");

		if((user==19009001 && parola==12345) || (user==19009002 && parola==54321)) // 2 kullanıcı mevcut	
		{
			system("CLS");

			do
			{
				if(user==19009001)
					printf("\t\t\t\tHesap: 1.hesabınız\n");
				if(user==19009002)
					printf("\t\t\t\tHesap: 2.hesabınız\n");
			printf("\t\t\t      İŞlem Menüsü\n\n");
			printf("1) Para Yatırma\n");
			printf("2) Para Çekme\n");
			printf("3) Bakiye Görüntüleme\n");
			printf("4) Para Gönderme\n");
			printf("5) Çıkış yapın \n\n");

			printf("Seçiminiz (1-5)");
			scanf_s("%d",&seçim2);

			if(seçim2!=1 && seçim2!=2 && seçim2!=3 && seçim2!=4 && seçim2!=5) // 1,2,3,4,5'den farklı seçim yapılırsa hata verır
			{
				printf("Hatalı giriş yaptınız. Lütfen tekrar deneyiniz...\a\n");
				printf("------------------------------------------------\n\n");
			}

			switch(seçim2)
			{
			case 1: // para yatırma
				printf("Yatıracağınız Para Miktarını TL Cinsinden Giriniz : ");
				scanf_s("%d",&yatırma);

				if(user==19009001)
				{	
					bakiye_19009001=bakiye_19009001 + yatırma;
					printf("Hesabınıza %d TL Yatırılıyor. . .\n", yatırma);
					Sleep(1500);
					printf("İşleminiz başarıyla gerçekleştirildi!\n");
					printf("Mevcut Bakiyeniz %dTL'dir.\n\n", bakiye_19009001);
				}
				if(user==19009002)
				{	
					bakiye_19009002=bakiye_19009002 + yatırma;
					printf("Hesabınıza %d TL Yatırılıyor. . .\n", yatırma);
					Sleep(1000);
					printf("İşleminiz başarıyla gerçekleştirildi!\n");
					printf("Mevcut Bakiyeniz %dTL'dir.\n\n", bakiye_19009002);
				}
				break;

			case 2: // para çekme
				printf("Çekeceğiniz Para Miktarını TL Cinsinden Giriniz :");
				scanf_s("%d",&çekme);

				if(user==19009001 && çekme<=bakiye_19009001)
				{	
					bakiye_19009001=bakiye_19009001 - çekme;
					printf("Hesabınızdan %d TL Çekiliyor. . .\n", çekme);
					Sleep(1500);
					printf("İşleminiz başarıyla gerçekleştirildi!\n");
					printf("Kalan Bakiyeniz %dTL'dir.\n\n", bakiye_19009001);
				}
				if(user==19009002 && çekme<=bakiye_19009002)
				{	
					bakiye_19009002=bakiye_19009002 - çekme;
					printf("Hesabınızdan %d TL Çekiliyor. . .\n", çekme);
					Sleep(1000);
					printf("İşleminiz başarıyla gerçekleştirildi!\n");
					printf("Kalan Bakiyeniz %dTL'dir.\n\n", bakiye_19009002);
				}
				else if(çekme>bakiye_19009002 || çekme>bakiye_19009002) // çekmek istenilen miktar bakiyeden büyükse uyarır
				{
								printf("\nHesabınızdan %d TL çekiliyor. . .\n", çekme);
								Sleep(1000);
								printf("\nYETERSİZ BAKİYE !!\a\n");
								printf("İşleminiz şuan gerçekleştirilemedi..\n\n");
								Sleep(600);
				}
				break;
				
			case 3: // bakiye görüntüleme
				if(user==19009001)
					printf("Mevcut Bakiyeniz %d TL'dir.\n\n", bakiye_19009001);
				if(user==19009002)
					printf("Mevcut Bakiyeniz %d TL'dir.\n\n", bakiye_19009002);
				break;

			case 4: // para gönderme
				printf("Göndereceğiniz Para Miktarını TL Olarak Giriniz: ");
				scanf_s("%d",&gonderme);

					if(user==19009001 && gonderme<=bakiye_19009001)
					{
						bakiye_19009001=bakiye_19009001 - gonderme;
						bakiye_19009002=bakiye_19009002 + gonderme;
						printf("Hesabınızdan %d TL 2. Hesabınıza Gönderiliyor. . .\n", gonderme);
						Sleep(1500);
						printf("İşleminiz Başarıyla Gerçekleştirildi.\n");
						printf("Mevcut Bakiyeniz %d TL'dir.\n\n", bakiye_19009001);
					}
					if(user==19009002 && gonderme<=bakiye_19009001)
					{
						bakiye_19009002=bakiye_19009002 - gonderme;
						bakiye_19009001=bakiye_19009001 + gonderme;
						printf("Hesabınızdan %d TL 1. Hesabınıza Gönderiliyor. . .\n", gonderme);
						Sleep(1500);
						printf("İşleminiz Başarıyla Gerçekleştirildi.\n");
						printf("Mevcut Bakiyeniz %d TL'dir.\n\n", bakiye_19009002);
					}
					else if(gonderme>bakiye_19009001 || gonderme>bakiye_19009002) //gönderilmek istenen bakiye yetersizse hata verir
					{
						printf("Hesabınızdan %d TL Gönderiliyor. . .\n", gonderme);
						Sleep(1500);
						printf("\n YETERSİZ BAKİYE !!\a\n");
						printf("\nMalesef İşleminiz Gerçekleştirilemedi..\n\n");
						Sleep(500);
					}
				break;
			case 5: // çıkış yapmak için
				printf("\nOturumunuz Kapatılıyor. . .");
				Sleep(1900);
				system("CLS");
				break;
			}
			}

			while(seçim2!=5);

			break;
		}

		else // hatalı giriş yapıldığında uyarı mesajı..
		{
			printf("Yanlış Giriş Yaptınız.	%d Deneme Hakkınız Kaldı..\a\n", 3 - hatalı);
			printf("-------------------------------------------------\n\n");
			hatalı++;
		}
		}
		if(hatalı==4) // 4. kez hatalı giriş yapıldığında ana menüye döner.
		{
			printf("3 Kez Yanlış Giriş Yaptınız. Ana Menüye Yönlendiriliyorsunuz..\a");
			Sleep(1500);
			system("CLS");
			break;
		}

		break;
	
		case 2: // çıkış mesajı
			printf("İyi günler diler tekrar bekleriz..\n\n");
			Sleep(2000);
			break;
		}
		if(seçim1==2) // ilk menüde çıkış seçilirse direkt olarak çıkar
			return 0;
		}
		system("pause");

		return 0;
	}

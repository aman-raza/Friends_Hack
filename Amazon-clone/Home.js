import React from "react";
import "./Home.css";
import Product from "./Product";

function Home() {
  return (
    <div className="home">
      <div className="home__container">
        <img
          className="home__image"
          src="https://images-eu.ssl-images-amazon.com/images/G/02/digital/video/merch2016/Hero/Covid19/Generic/GWBleedingHero_ENG_COVIDUPDATE__XSite_1500x600_PV_en-GB._CB428684220_.jpg"
          alt=""
        />

        <div className="home__row">
          <Product
            id="90829332"
            title="HP Pavillion DX08w6PPX 15.6 inch Gaming Laptop"
            price={1000}
            rating={4}
            image="https://images-na.ssl-images-amazon.com/images/I/71nLcz30aOL._SL1500_.jpg"
            
          />
          <Product
           id="90829332"
           title="One plus NORD (Rich Blue) 6 GB + 128 GB"
           price={1094.98}
           rating={4}
           image="https://images-na.ssl-images-amazon.com/images/I/71g4%2BnfB3QL._SL1500_.jpg"
           
          />
        </div>

        <div className="home__row">
          <Product
            id="4903850"
            title="Samsung LC49RG90SSUXEN 49' Curved LED Gaming Monitor"
            price={199.99}
            rating={3}
            image="https://images-na.ssl-images-amazon.com/images/I/71Swqqe7XAL._AC_SX466_.jpg"
          />
          <Product
            id="23445930"
            title="Amazon Echo (3rd generation) | Smart speaker with Alexa, Charcoal Fabric"
            price={98.99}
            rating={5}
            image="https://media.very.co.uk/i/very/P6LTG_SQ1_0000000071_CHARCOAL_SLf?$300x400_retinamobilex2$"
          />
          <Product
            id="3254354345"
            title="New Apple iPad Pro (12.9-inch, Wi-Fi, 128GB) - Silver (4th Generation)"
            price={598.99}
            rating={4}
            image="https://images-na.ssl-images-amazon.com/images/I/816ctt5WV5L._AC_SX385_.jpg"
          />
        </div>

        <div className="home__row">
          <Product
            id="90829332"
            title="Samsung LC49RG90SSUXEN 49' Curved LED Gaming Monitor - Super Ultra Wide Dual WQHD 5120 x 1440"
            price={1094.98}
            rating={4}
            image="https://images-na.ssl-images-amazon.com/images/I/6125mFrzr6L._AC_SX355_.jpg"
          />
                <div className="home__container">

                  <div className="home__row">
                  <Product
            id="90829332"
            title="Up to 40% off TV and other appliances"
            price={200}
            rating={4}
            image="https://images-eu.ssl-images-amazon.com/images/G/31/img20/TVs/Jupiter20/GW/V261912046_IN_HETV_MSO_Jupiter_DesktopGateway_CategoryCard_379X304._SY304_CB418873635_.jpg"
          />
                  <div className="home__row">
                  <Product
            id="90829332"
            title="Canon EOS 1500D with single lens kit"
            price={800.98}
            rating={5}
            image="https://images-na.ssl-images-amazon.com/images/I/914hFeTU2-L._SL1500_.jpg"
          />
                  <div className="home__row">
                  <Product
                  id="12321341"
                  title="The Lean Startup: How Constant Innovation Creates Radically Successful Businesses Paperback"
                  price={11.96}
                  rating={5}
                  image="https://images-na.ssl-images-amazon.com/images/I/51Zymoq7UnL._SX325_BO1,204,203,200_.jpg"
          
          />
                
                  <div className="home__row">
                  <Product
            id="90829332"
            title="One plus Buds ( True Wireless)"
            price={300}
            rating={4}
            image="https://images-na.ssl-images-amazon.com/images/I/616G520BWDL._SL1500_.jpg"
          />
        

                  
                    </div>
                    </div>
                    </div>
                    </div>
                    </div>
          
        </div>
      </div>
    </div>
  );
}

export default Home;
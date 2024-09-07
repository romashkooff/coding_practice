import React from "react";
import "./style.css";
import {
  FaGithub,
  FaInstagram,
  FaFacebookF,
  FaLinkedin,
  FaYoutube,
  FaTwitch,
} from "react-icons/fa";
import { socialprofils } from "../../content_option";

export const Socialicons = () => {
  const socialLinks = [
    { platform: "instagram", icon: <FaInstagram /> },
    { platform: "github", icon: <FaGithub /> },
    { platform: "facebook", icon: <FaFacebookF /> },
    { platform: "linkedin", icon: <FaLinkedin /> },
    { platform: "youtube", icon: <FaYoutube /> },
    { platform: "twitch", icon: <FaTwitch /> },
  ];

  return (
    <div className="stick_follow_icon">
      <ul>
        {socialLinks.map(
          ({ platform, icon }) =>
            socialprofils[platform] && (
              <li key={platform}>
                <a href={socialprofils[platform]} aria-label={platform}>
                  {icon}
                </a>
              </li>
            )
        )}
      </ul>
      <p>Follow Me</p>
    </div>
  );
};

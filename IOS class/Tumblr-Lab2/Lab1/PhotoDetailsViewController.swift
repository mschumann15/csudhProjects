//
//  PhotoDetailsViewController.swift
//  Lab1
//
//  Created by Marcus Schumann on 11/11/18.
//  Copyright © 2018 Marcus Schumann. All rights reserved.
//

import UIKit

class PhotoDetailsViewController: UIViewController {

    
    @IBOutlet weak var photoView: UIImageView!
    
    var post: [String: Any]?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let post = post {
            if let photos = post["photos"] as? [[String: Any]] {
                let photo = photos[0]
                
                let originalSize = photo["original_size"] as! [String: Any]
                
                let urlString = originalSize["url"] as! String
                
                let url = URL(string: urlString)
                
                photoView.af_setImage(withURL: url!)
            }
        }
        

        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
